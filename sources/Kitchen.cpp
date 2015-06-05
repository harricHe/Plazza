/*
** Kitchen.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 16:19:11 2015 nlequain
** Last update Sun Apr 26 22:44:59 2015 nlequain
*/

#include <iostream>
#include <sstream>
#include "MutexScopedLock.hpp"
#include "Kitchen.hpp"
#include "Doe.hpp"
#include "Eggplant.hpp"
#include "GoatCheese.hpp"
#include "Gruyere.hpp"
#include "Ham.hpp"
#include "Mushroom.hpp"
#include "Steak.hpp"
#include "Tomato.hpp"
#include "Fantasia.hpp"
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Royal.hpp"
#include "Gourmand.hpp"

Kitchen::Kitchen(double timeMultiplier, size_t cooksNumber, unsigned int freezerRefreshSpeed, const std::string & namedPipeFromReception, const std::string & namedPipeToReception)
{
	for (size_t i = 0; i < cooksNumber; ++i)
		this->_cooks.push_back(Cook(timeMultiplier, this));
	this->_freezer = new Freezer(freezerRefreshSpeed, this);
	this->_freezer->addIngredientType(new Doe());
	this->_freezer->addIngredientType(new Eggplant());
	this->_freezer->addIngredientType(new GoatCheese());
	this->_freezer->addIngredientType(new Gruyere());
	this->_freezer->addIngredientType(new Ham());
	this->_freezer->addIngredientType(new Mushroom());
	this->_freezer->addIngredientType(new Steak());
	this->_freezer->addIngredientType(new Tomato());
	this->_recipeFactory.addModel(new Margarita());
	this->_recipeFactory.addModel(new Regina());
	this->_recipeFactory.addModel(new Americana());
	this->_recipeFactory.addModel(new Fantasia());
	this->_recipeFactory.addModel(new Royal());
	this->_recipeFactory.addModel(new Gourmand());
	this->_pipeFromReception = new InputNamedPipe(namedPipeFromReception);
	this->_pipeToReception = new OutputNamedPipe(namedPipeToReception);
}

Kitchen::~Kitchen()
{
	delete this->_freezer;
}

void Kitchen::run()
{
	std::string serializedOrder;
	ARecipe::Order order;
	ARecipe * recipeToCook;

	this->_pipeFromReception->open();
	this->_pipeToReception->open();
	this->launchThreads();
	while (true)
	{
		*this->_pipeFromReception >> serializedOrder;
		if (ASerializable::getType(serializedOrder) == ASerializable::Recipe)
		{
			order.unpack(serializedOrder);
			recipeToCook = this->_recipeFactory.create(order.getRecipeType(), order.getFoodType(), order.getSize());
			while (not order.isReady())
				recipeToCook->addRequirement(order.getNextIngredient());
			this->addCommand(recipeToCook);
		}
	}
	this->stopThreads();
	this->_pipeFromReception->close();
	this->_pipeToReception->close();
}

void Kitchen::launchThreads()
{
	for (std::list<Cook>::iterator cook = this->_cooks.begin(); cook != this->_cooks.end(); ++cook)
		cook->launchThread();
	if (this->_freezer)
		this->_freezer->launchThread();
}

void Kitchen::stopThreads()
{
	for (std::list<Cook>::iterator cook = this->_cooks.begin(); cook != this->_cooks.end(); ++cook)
		cook->stopThread();
	if (this->_freezer)
		this->_freezer->stopThread();
}

void Kitchen::update(Cook * cook)
{
	MutexScopedLock scopedLock(this->_commandMutex);

	ARecipe * commandReady = cook->sendCommand();
	if (commandReady != NULL)
	{
		this->_outputMutex.lock();
		*this->_pipeToReception << commandReady->getOrder()->pack();
		this->_outputMutex.unlock();
		delete commandReady;
		this->sendCookBusyNotification(-1);
	}
	while (this->_commandList.empty())
		this->_commandWaiter.sleep(this->_commandMutex);
	cook->setCommand(this->_commandList.front());
	this->_commandList.pop();
	this->sendCookBusyNotification(+1);
}

void Kitchen::sendCookBusyNotification(int modifier)
{
	std::stringstream notification;

	ASerializable::writeType(notification, ASerializable::Cook);
	notification << modifier;
	this->_outputMutex.lock();
	*this->_pipeToReception << notification.str();
	this->_outputMutex.unlock();
}

void Kitchen::update(Freezer * freezer)
{
	this->_outputMutex.lock();
	*this->_pipeToReception << freezer->getSerializableFreezer()->pack();
	this->_outputMutex.unlock();
}

AIngredient * Kitchen::getIngredientFromFreezer(AIngredient::TypeIngredient ingredientType)
{
	return this->_freezer->getIngredient(ingredientType);
}

void Kitchen::addCommand(ARecipe * command)
{
	MutexScopedLock scopedLock(this->_commandMutex);

	this->_commandList.push(command);
	this->_commandWaiter.wake();
}
