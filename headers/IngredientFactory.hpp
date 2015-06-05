/*
** IngredientFactory.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 12:49:12 2015 nlequain
** Last update Sun Apr 26 19:19:30 2015 nlequain
*/

#ifndef __INGREDIENTFACTORY_HH__
# define __INGREDIENTFACTORY_HH__

# include "Factory.hpp"
# include "AIngredient.hpp"

class IngredientFactory : public Factory<enum AIngredient::TypeIngredient, AIngredient>, public Factory<std::string, AIngredient>
{
public:
	IngredientFactory();
	~IngredientFactory();

	void addModel(AIngredient * model);
	AIngredient * create(const enum AIngredient::TypeIngredient & ingredientType);
	AIngredient * create(const std::string & ingredientName);
	std::string * getIngredientName(enum AIngredient::TypeIngredient ingredientType);
};

#endif /* !__INGREDIENTFACTORY_HH__ */