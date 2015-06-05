/*
** KitchenManager.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:50:59 2015 nlequain
** Last update Sun Apr 26 22:44:57 2015 nlequain
*/

#include <sstream>
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"
#include "Doe.hpp"
#include "Eggplant.hpp"
#include "GoatCheese.hpp"
#include "Gruyere.hpp"
#include "Ham.hpp"
#include "Mushroom.hpp"
#include "Steak.hpp"
#include "Tomato.hpp"
#include "KitchenManager.hpp"
#include "Reception.hpp"
#include "Royal.hpp"
#include "Gourmand.hpp"

KitchenManager::KitchenManager(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, Reception * reception) : AObservable(reception), _timeMultiplier(timeMultiplier), _cooksPerKitchen(cooksPerKitchen), _freezerRefreshSpeed(freezerRefreshSpeed)
{
	this->_recipeFactory.addModel(new Margarita());
	this->_recipeFactory.addModel(new Regina());
	this->_recipeFactory.addModel(new Americana());
	this->_recipeFactory.addModel(new Fantasia());
	this->_recipeFactory.addModel(new Royal());
	this->_recipeFactory.addModel(new Gourmand());
	this->_ingredientFactory.addModel(new Doe());
	this->_ingredientFactory.addModel(new Eggplant());
	this->_ingredientFactory.addModel(new GoatCheese());
	this->_ingredientFactory.addModel(new Gruyere());
	this->_ingredientFactory.addModel(new Ham());
	this->_ingredientFactory.addModel(new Mushroom());
	this->_ingredientFactory.addModel(new Steak());
	this->_ingredientFactory.addModel(new Tomato());
	this->launchThread();
}

KitchenManager::~KitchenManager()
{
	this->stopThread();
	for (std::list<KitchenTracker *>::iterator kitchen = this->_kitchens.begin(); kitchen != this->_kitchens.end(); ++kitchen)
		delete *kitchen;
}

bool KitchenManager::treatOrder(Parser::Order & order)
{
	this->_errors.clear();
	this->_errors.str("");
	ARecipe * recipeToCook = this->orderToRecipe(order);
	if (recipeToCook == NULL)
	{
		this->_errorString = this->_errors.str();
		return false;
	}
	KitchenTracker * targetKitchen = this->getLessBusyKitchen();
	if (targetKitchen == NULL)
	{
		this->_kitchens.push_back(new KitchenTracker(this->_timeMultiplier, this->_cooksPerKitchen, this->_freezerRefreshSpeed, this));
		targetKitchen = this->_kitchens.back();
	}
	*targetKitchen << recipeToCook->getOrder()->pack();
	targetKitchen->addOrder();
	this->_errorString = this->_errors.str();
	return true;
}

KitchenTracker * KitchenManager::getLessBusyKitchen() const
{
	std::list<KitchenTracker *>::const_iterator lessBusy = this->_kitchens.begin();

	if (this->_kitchens.empty())
		return NULL;
	for (std::list<KitchenTracker *>::const_iterator kitchen = this->_kitchens.begin(); kitchen != this->_kitchens.end(); ++kitchen)
	{
		if ((*kitchen)->getOrderCount() < (*lessBusy)->getOrderCount())
			lessBusy = kitchen;
	}
	if ((*lessBusy)->getOrderCount() >= this->_cooksPerKitchen * 2)
		return NULL;

	return *lessBusy;
}

ARecipe * KitchenManager::orderToRecipe(Parser::Order & order)
{
	ARecipe * recipe = this->_recipeFactory.create(order.getRecipeType(), order.getFoodType(), order.getSize());
	if (recipe == NULL)
	{
		this->_errors << "Unknown recipe : " << order.getRecipeType() << " " << order.getFoodType() << ". ";
		return NULL;
	}
	while (not order.isReady())
	{
		std::string ingredientName = order.getNextAdditionalIngredient();
		AIngredient * ingredient = this->_ingredientFactory.create(ingredientName);
		if (ingredient != NULL)
			recipe->addDecorator(ingredient);
		else
			this->_errors << "Unknown ingredient : " << ingredientName << ". ";
	}
	return recipe;
}

void KitchenManager::run()
{
	double refreshSpeed = 0.1;

	while (true)
	{
		for (std::list<KitchenTracker *>::iterator kitchen = this->_kitchens.begin(); kitchen != this->_kitchens.end(); ++kitchen)		
		{
			if ((*kitchen)->mustClose())
			{
				delete *kitchen;
				this->_kitchens.erase(kitchen);
				break;
			}
		}
		usleep(refreshSpeed * 1000000);
	}
}

void KitchenManager::update(KitchenTracker * kitchenTracker)
{
	ARecipe::Order order;
	ARecipe * recipeReady;
	AIngredient * ingredient;
	std::ostringstream orderToString;

	this->_updateMessage = kitchenTracker->getUpdateMessage();
	if (this->_updateMessage->getMessageType() == ASerializable::Recipe)
	{
		order.unpack(this->_updateMessage->getMessage());
		recipeReady = this->_recipeFactory.create(order.getRecipeType(), order.getFoodType(), order.getSize());
		while (not order.isReady())
		{
			ingredient = this->_ingredientFactory.create(order.getNextIngredient());
			if (ingredient != NULL)
				recipeReady->addDecorator(ingredient);
		}
		orderToString << *recipeReady;
		this->_updateMessage->setMessage(orderToString.str());
	}
	this->notify();
}

KitchenTracker::KitchenMessage * KitchenManager::getUpdateMessage()
{
	return this->_updateMessage;
}

const std::string & KitchenManager::getError()
{
	return this->_errorString;	
}