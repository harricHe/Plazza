/*
** RecipeFactory.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 10:29:09 2015 nlequain
** Last update Sun Apr 26 10:30:15 2015 nlequain
*/

#include <algorithm>
#include "RecipeFactory.hpp"

RecipeFactory::RecipeFactory()
{

}

RecipeFactory::~RecipeFactory()
{

}

void RecipeFactory::addModel(ARecipe * model)
{
	std::string recipeNameLower = model->getRecipeName();
	std::string foodNameLower = model->getName();

	std::transform(recipeNameLower.begin(), recipeNameLower.end(), recipeNameLower.begin(), ::tolower);
	std::transform(foodNameLower.begin(), foodNameLower.end(), foodNameLower.begin(), ::tolower);
	Factory<recipe_numerical_data, ARecipe>::addModel(recipe_numerical_data(model->getRecipeType(), model->getFoodType()), dynamic_cast<ARecipe *>(model->duplicate()));
	Factory<recipe_string_data, ARecipe>::addModel(recipe_string_data(recipeNameLower, foodNameLower), dynamic_cast<ARecipe *>(model->duplicate()));
	delete model;
}

ARecipe * RecipeFactory::create(enum ARecipe::TypeRecipe recipeType, int foodType, enum ARecipe::TaillePizza size)
{
	ARecipe * recipe = Factory<recipe_numerical_data, ARecipe>::create(recipe_numerical_data(recipeType, foodType));
	if (recipe == NULL)
		return NULL;
	recipe->setSize(size);
	return recipe;
}

ARecipe * RecipeFactory::create(const std::string & recipeName, const std::string & foodName, enum ARecipe::TaillePizza size)
{
	std::string recipeNameLower = recipeName;
	std::string foodNameLower = foodName;

	std::transform(recipeNameLower.begin(), recipeNameLower.end(), recipeNameLower.begin(), ::tolower);
	std::transform(foodNameLower.begin(), foodNameLower.end(), foodNameLower.begin(), ::tolower);
	ARecipe * recipe = Factory<recipe_string_data, ARecipe>::create(recipe_string_data(recipeNameLower, foodNameLower));
	if (recipe == NULL)
		return NULL;
	recipe->setSize(size);
	return recipe;
}