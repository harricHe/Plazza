/*
** AIngredient.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 20:19:48 2015 nlequain
** Last update Sun Apr 26 09:46:41 2015 nlequain
*/

#ifndef __AINGREDIENT_HH__
# define __AINGREDIENT_HH__

# include <list>
# include "AFood.hpp"
# include "IDuplicable.hpp"

class AIngredient : public AFood<AIngredient>, virtual public IDuplicable
{
public:
	enum TypeIngredient {
		Doe = 1,
		Eggplant,
		GoatCheese,
		Gruyere,
		Ham,
		Mushroom,
		Steak,
		Tomato
	};

private:
	enum TypeIngredient _ingredientType;

public:
	virtual ~AIngredient();
	enum AIngredient::TypeIngredient getIngredientType() const;
	void fillIngredientList(std::list<enum AIngredient::TypeIngredient> & ingredientList) const;

protected:
	AIngredient(enum AIngredient::TypeIngredient ingredientType, const std::string & name, double cookingTime);
};

std::ostream & operator<<(std::ostream & os, const AIngredient & ingredient);

#endif /* !__AINGREDIENT_HH__ */