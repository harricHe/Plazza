/*
** ARecipe.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 10:48:29 2015 nlequain
** Last update Sun Apr 26 20:44:42 2015 nlequain
*/

#include <sstream>
#include "ARecipe.hpp"

/*
** ARecipe
*/

ARecipe::ARecipe(enum ARecipe::TypeRecipe recipeType, int foodType, const std::string & recipeName, const std::string & name, double cookingTime, enum ARecipe::TaillePizza size) :
	AFood(name, cookingTime), _recipeType(recipeType), _recipeName(recipeName), _foodType(foodType), _size(size)
{

}

ARecipe::~ARecipe()
{

}

void ARecipe::addDecorator(AIngredient * decorator)
{
	ADecorable<AIngredient>::addDecorator(decorator);
	this->_requiredFood.remove(decorator->getIngredientType());
}

void ARecipe::addRequirement(AIngredient::TypeIngredient requirement)
{
	this->_requiredFood.push_back(requirement);
}

AIngredient::TypeIngredient ARecipe::getNextRequirement() const
{
	return this->_requiredFood.front();
}

bool ARecipe::isReady() const
{
	return this->_requiredFood.empty();
}

enum ARecipe::TypeRecipe ARecipe::getRecipeType() const
{
	return this->_recipeType;
}

int ARecipe::getFoodType() const
{
	return this->_foodType;
}

ARecipe::TaillePizza ARecipe::getSize() const
{
	return this->_size;
}

const std::string & ARecipe::getRecipeName() const
{
	return this->_recipeName;
}

void ARecipe::setSize(ARecipe::TaillePizza size)
{
	this->_size = size;
}

ARecipe::Order * ARecipe::getOrder() const
{
	ARecipe::Order * order = new Order();
	std::list<enum AIngredient::TypeIngredient> ingredientList;

	order->setRecipeType(this->_recipeType);
	order->setFoodType(this->_foodType);
	order->setSize(this->_size);
	if (this->_decorator)
		this->_decorator->fillIngredientList(ingredientList);
	for (std::list<enum AIngredient::TypeIngredient>::iterator ingredient = ingredientList.begin(); ingredient != ingredientList.end(); ++ingredient)
		order->addIngredient(*ingredient);
	return order;
}

std::ostream & operator<<(std::ostream & os, const ARecipe & recipe)
{
	const AFood<AIngredient> * self = &recipe;

	os << recipe.getRecipeName() << " " << *self;
	return os;
}

/*
** Order
*/

ARecipe::Order::Order()
{

}

ARecipe::Order::~Order()
{

}

std::string ARecipe::Order::pack() const
{
	std::stringstream serializedOrder;

	ASerializable::writeType(serializedOrder, ASerializable::Recipe);
	serializedOrder << this->_recipeType;
	serializedOrder << SERIALIZER_CATEGORY_SEPARATOR;
	serializedOrder << this->_foodType;
	serializedOrder << SERIALIZER_CATEGORY_SEPARATOR;
	serializedOrder << this->_size;
	serializedOrder << SERIALIZER_CATEGORY_SEPARATOR;
	for (std::list<enum AIngredient::TypeIngredient>::const_iterator ingredient = this->_ingredientList.begin(); ingredient != this->_ingredientList.end(); ++ingredient)
	{
		if (ingredient != this->_ingredientList.begin())
			serializedOrder << SERIALIZER_SUBCATEGORY_SEPARATOR;
		serializedOrder << *ingredient;
	}
	return serializedOrder.str();
}

void ARecipe::Order::unpack(const std::string & data)
{
	std::string parsable_data(data);

	this->getValue<ARecipe::TypeRecipe>(parsable_data, this->_recipeType);
	this->getValue<int>(parsable_data, this->_foodType);
	this->getValue<ARecipe::TaillePizza>(parsable_data, this->_size);
	this->getIngredientsFromCSV(parsable_data);
}

void ARecipe::Order::getIngredientsFromCSV(std::string & parsable_data)
{
	std::stringstream dataConverter;
	std::size_t pos = 0;
	int valueIntConverter;

	while (pos != std::string::npos)
	{
		pos = parsable_data.find(SERIALIZER_SUBCATEGORY_SEPARATOR);
		dataConverter.clear();
		dataConverter.str(parsable_data.substr(0, pos));
		valueIntConverter = 0;
		dataConverter >> valueIntConverter;
		if (not dataConverter.fail())
			this->_ingredientList.push_back(static_cast<AIngredient::TypeIngredient>(valueIntConverter));
		parsable_data.erase(0, pos + 1);
	}
}

bool ARecipe::Order::isReady() const
{
	return this->_ingredientList.empty();
}

void ARecipe::Order::setRecipeType(enum ARecipe::TypeRecipe recipeType)
{
	this->_recipeType = recipeType;
}

void ARecipe::Order::setFoodType(int foodType)
{
	this->_foodType = foodType;
}

void ARecipe::Order::setSize(enum ARecipe::TaillePizza size)
{
	this->_size = size;
}

void ARecipe::Order::addIngredient(enum AIngredient::TypeIngredient ingredient)
{
	this->_ingredientList.push_back(ingredient);
}

enum ARecipe::TypeRecipe ARecipe::Order::getRecipeType() const
{
	return this->_recipeType;
}

int ARecipe::Order::getFoodType() const
{
	return this->_foodType;
}

enum ARecipe::TaillePizza ARecipe::Order::getSize() const
{
	return this->_size;
}

enum AIngredient::TypeIngredient ARecipe::Order::getNextIngredient()
{
	AIngredient::TypeIngredient ingredient = this->_ingredientList.front();
	this->_ingredientList.pop_front();
	return ingredient;
}

