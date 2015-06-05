/*
** AIngredient.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 20:55:52 2015 nlequain
** Last update Sun Apr 26 09:46:46 2015 nlequain
*/

#include "AIngredient.hpp"

AIngredient::AIngredient(enum AIngredient::TypeIngredient ingredientType, const std::string & name, double cookingTime) :
	AFood(name, cookingTime), _ingredientType(ingredientType)
{

}

AIngredient::~AIngredient()
{

}

enum AIngredient::TypeIngredient AIngredient::getIngredientType() const
{
	return this->_ingredientType;
}

void AIngredient::fillIngredientList(std::list<enum AIngredient::TypeIngredient> & ingredientList) const
{
	ingredientList.push_front(this->_ingredientType);
	if (this->_decorator)
		this->_decorator->fillIngredientList(ingredientList);
}

std::ostream & operator<<(std::ostream & os, const AIngredient & ingredient)
{
	const AFood<AIngredient> * self = &ingredient;

	os << ", with " << *self;
	return os;
}
