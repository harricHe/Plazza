/*
** APizza.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 20:48:54 2015 nlequain
** Last update Sat Apr 25 16:41:22 2015 nlequain
*/

#ifndef __APIZZA_HH__
# define __APIZZA_HH__

# include "ARecipe_CRTP.hpp"

template <typename T>
class APizza : public ARecipe_CRTP<T>
{
public:
	enum TypePizza {
		Regina = 1,
		Margarita = 2,
		Americaine = 4,
		Fantasia = 8
	};

public:
	virtual ~APizza() {}

protected:
	APizza(enum APizza::TypePizza pizzaType, const std::string & name, double cookingTime, enum ARecipe::TaillePizza size) : ARecipe_CRTP<T>(ARecipe::Pizza, pizzaType, "pizza", name, cookingTime, size) {}
};

#endif /* !__APIZZA_HH__ */