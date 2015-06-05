/*
** RecipeFactory.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 10:23:58 2015 nlequain
** Last update Wed Apr 22 16:33:38 2015 nlequain
*/

#ifndef __RECIPEFACTORY_HH__
# define __RECIPEFACTORY_HH__

# include <utility>
# include "Factory.hpp"
# include "ARecipe.hpp"

class RecipeFactory : public Factory<std::pair<enum ARecipe::TypeRecipe, int>, ARecipe>, public Factory<std::pair<std::string, std::string>, ARecipe>
{
private:
	typedef std::pair<enum ARecipe::TypeRecipe, int> recipe_numerical_data;
	typedef std::pair<std::string, std::string> recipe_string_data;

public:
	RecipeFactory();
	~RecipeFactory();

	void addModel(ARecipe * model);
	ARecipe * create(enum ARecipe::TypeRecipe recipeType, int foodType, enum ARecipe::TaillePizza size);
	ARecipe * create(const std::string & recipeName, const std::string & foodName, enum ARecipe::TaillePizza size);
};

#endif /* !__RECIPEFACTORY_HH__ */