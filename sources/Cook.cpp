/*
** Cook.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 16:05:31 2015 nlequain
** Last update Sun Apr 26 11:39:03 2015 nlequain
*/

#include "Cook.hpp"
#include "Kitchen.hpp"
#include "AIngredient.hpp"

Cook::Cook(double timeMultiplier, Kitchen * kitchen) : AObservable(kitchen), _commandToCook(NULL), _timeMultiplier(timeMultiplier)
{

}

Cook::~Cook()
{
	if (this->_commandToCook != NULL)
		delete this->_commandToCook;
}

void Cook::run()
{
	while (true)
	{
		this->notify();
		while (this->_commandToCook->isReady() == false)
		{
			AIngredient * ingredient = this->getObserver().getIngredientFromFreezer(this->_commandToCook->getNextRequirement());
			if (ingredient == NULL)
			{
				delete this->_commandToCook;
				this->_commandToCook = NULL;
				break;
			}
			this->_commandToCook->addDecorator(ingredient);
		}
		if (this->_commandToCook)
			this->_commandToCook->cook(this->_timeMultiplier);
	}
}

void Cook::setCommand(ARecipe * command)
{
	this->_commandToCook = command;
}

ARecipe * Cook::sendCommand()
{
	ARecipe * command = this->_commandToCook;
	this->_commandToCook = NULL;
	return command;
}