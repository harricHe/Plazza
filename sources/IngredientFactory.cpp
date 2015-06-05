/*
** IngredientFactory.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 12:51:12 2015 nlequain
** Last update Sun Apr 26 19:20:17 2015 nlequain
*/

#include <algorithm>
#include "IngredientFactory.hpp"

IngredientFactory::IngredientFactory()
{

}

IngredientFactory::~IngredientFactory()
{

}

void IngredientFactory::addModel(AIngredient * model)
{
	std::string ingredientNameLower = model->getName();

	std::transform(ingredientNameLower.begin(), ingredientNameLower.end(), ingredientNameLower.begin(), ::tolower);
	Factory<enum AIngredient::TypeIngredient, AIngredient>::addModel(model->getIngredientType(), dynamic_cast<AIngredient *>(model->duplicate()));
	Factory<std::string, AIngredient>::addModel(ingredientNameLower, dynamic_cast<AIngredient *>(model->duplicate()));
	delete model;
}

AIngredient * IngredientFactory::create(const enum AIngredient::TypeIngredient & ingredientType)
{
	return Factory<enum AIngredient::TypeIngredient, AIngredient>::create(ingredientType);
}

AIngredient * IngredientFactory::create(const std::string & ingredientName)
{
	std::string ingredientNameLower = ingredientName;

	std::transform(ingredientNameLower.begin(), ingredientNameLower.end(), ingredientNameLower.begin(), ::tolower);
	return Factory<std::string, AIngredient>::create(ingredientNameLower);
}

std::string * IngredientFactory::getIngredientName(enum AIngredient::TypeIngredient ingredientType)
{
	AIngredient * ingredient;
	std::string * ingredientName;

	ingredient = Factory<enum AIngredient::TypeIngredient, AIngredient>::create(ingredientType);
	if (ingredient == NULL)
		return NULL;
	ingredientName = new std::string(ingredient->getName());
	delete ingredient;	
	return ingredientName;
}