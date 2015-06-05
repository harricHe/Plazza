/*
** Freezer.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 13:48:08 2015 nlequain
** Last update Sun Apr 26 20:44:56 2015 nlequain
*/

#include "Freezer.hpp"
#include "MutexScopedLock.hpp"
#include "Kitchen.hpp"

/*
** Freezer
*/

Freezer::Freezer(unsigned int microsecondsToReplace, Kitchen * kitchen) : AObservable(kitchen), _microsecondsToReplace(microsecondsToReplace * 1000)
{

}

Freezer::~Freezer()
{

}

void Freezer::run()
{
	while (true)
	{
		this->notify();
		usleep(this->_microsecondsToReplace);
		this->_ingredientMutex.lock();
		for (std::map<AIngredient::TypeIngredient, unsigned int>::iterator stock = this->_ingredientStock.begin(); stock != this->_ingredientStock.end(); ++stock)
			++(stock->second);
		this->_ingredientMutex.unlock();
		this->_stockWaiter.wake();
	}
}

void Freezer::addIngredientType(AIngredient * ingredient)
{
	MutexScopedLock scopedLock(this->_ingredientMutex);

	if (this->_ingredientStock.find(ingredient->getIngredientType()) != this->_ingredientStock.end())
		return ;
	this->_ingredientStock[ingredient->getIngredientType()] = 5;
	this->_ingredientFactory.addModel(ingredient);
}

AIngredient * Freezer::getIngredient(AIngredient::TypeIngredient ingredientType)
{
	MutexScopedLock scopedLock(this->_ingredientMutex);

	if (this->_ingredientStock.find(ingredientType) == this->_ingredientStock.end())
		return (NULL);
	while (this->_ingredientStock[ingredientType] == 0) // <while> pour relocker si l'ingredient est deja pris par un autre thread
		this->_stockWaiter.sleep(this->_ingredientMutex);
	this->_ingredientStock[ingredientType] -= 1;
	this->notify();
	return (this->_ingredientFactory.create(ingredientType));
}

Freezer::SerializableFreezer * Freezer::getSerializableFreezer() const
{
	Freezer::SerializableFreezer * serializableFreezer = new Freezer::SerializableFreezer();

	for (std::map<AIngredient::TypeIngredient, unsigned int>::const_iterator ingredient = this->_ingredientStock.begin(); ingredient != this->_ingredientStock.end(); ++ingredient)
		serializableFreezer->addIngredientStock(ingredient->first, ingredient->second);
	return serializableFreezer;
}

/*
** SerializableFreezer
*/

Freezer::SerializableFreezer::SerializableFreezer()
{

}

Freezer::SerializableFreezer::~SerializableFreezer()
{

}

std::string Freezer::SerializableFreezer::pack() const
{
	std::stringstream serializedOrder;

	ASerializable::writeType(serializedOrder, ASerializable::Fridge);
	for (std::map<AIngredient::TypeIngredient, unsigned int>::const_iterator ingredient = this->_ingredientStock.begin(); ingredient != this->_ingredientStock.end(); ++ingredient)
	{
		if (ingredient != this->_ingredientStock.begin())
			serializedOrder << SERIALIZER_CATEGORY_SEPARATOR;
		serializedOrder << ingredient->first;
		serializedOrder << SERIALIZER_SUBCATEGORY_SEPARATOR;
		serializedOrder << ingredient->second;
	}
	return serializedOrder.str();
}

void Freezer::SerializableFreezer::unpack(const std::string & data)
{
	std::string parsableData = data;
	std::size_t pos = 0;

	while (pos != std::string::npos)
	{
		pos = parsableData.find(SERIALIZER_CATEGORY_SEPARATOR);
		this->parseSingleData(parsableData.substr(0, pos));
		parsableData.erase(0, pos + 1);
	}
}

void Freezer::SerializableFreezer::parseSingleData(const std::string & data)
{
	std::string parsableData = data;
	std::stringstream converter;
	std::size_t pos;
	int valueIntConverter;
	AIngredient::TypeIngredient type;
	unsigned int stock;

	pos = parsableData.find(SERIALIZER_SUBCATEGORY_SEPARATOR);
	if (pos == std::string::npos)
		return;

	converter.clear();
	converter << parsableData.substr(0, pos);
	converter >> valueIntConverter;
	if (converter.fail())
		return;
	type = static_cast<AIngredient::TypeIngredient>(valueIntConverter);

	converter.clear();
	converter << parsableData.substr(pos + 1);
	converter >> stock;
	if (converter.fail())
		return;

	this->addIngredientStock(type, stock);
}

void Freezer::SerializableFreezer::addIngredientStock(AIngredient::TypeIngredient ingredient, unsigned int stock)
{
	if (this->_ingredientStock.find(ingredient) == this->_ingredientStock.end())
		this->_ingredientStock[ingredient] = stock;
}

const std::map<AIngredient::TypeIngredient, unsigned int> & Freezer::SerializableFreezer::getIngredientStock() const
{
	return this->_ingredientStock;
}

