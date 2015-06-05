/*
** Freezer.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 13:17:18 2015 nlequain
** Last update Sun Apr 26 20:18:25 2015 nlequain
*/

#ifndef __FREEZER_HH__
# define __FREEZER_HH__

#include <map>
#include "AThreadable.hpp"
#include "Mutex.hpp"
#include "ConditionalVariable.hpp"
#include "IngredientFactory.hpp"
#include "ASerializable.hpp"
#include "AObservable.hpp"

class Kitchen;

class Freezer : public AThreadable, public AObservable<Freezer, Kitchen>
{
public:
	class SerializableFreezer : public ASerializable
	{
	private:
		std::map<AIngredient::TypeIngredient, unsigned int> _ingredientStock;

	public:
		SerializableFreezer();
		~SerializableFreezer();

		std::string pack() const;
		void unpack(const std::string & data);

		void addIngredientStock(AIngredient::TypeIngredient ingredient, unsigned int stock);
		const std::map<AIngredient::TypeIngredient, unsigned int> & getIngredientStock() const;

	private:
		void parseSingleData(const std::string & data);
	};

private:
	std::map<AIngredient::TypeIngredient, unsigned int> _ingredientStock;
	IngredientFactory _ingredientFactory;
	Mutex _ingredientMutex;
	ConditionalVariable _stockWaiter;
	int _microsecondsToReplace;

public:
	Freezer(unsigned int microsecondsToReplace, Kitchen * kitchen);
	~Freezer();
	void run();
	void addIngredientType(AIngredient * ingredient);
	AIngredient * getIngredient(AIngredient::TypeIngredient ingredientType);
	Freezer::SerializableFreezer * getSerializableFreezer() const;
};

#endif /* !__FREEZER_HH__ */