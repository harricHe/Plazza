/*
** ABurger.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 22:33:34 2015 nlequain
** Last update Sun Apr 26 22:42:00 2015 nlequain
*/

#ifndef __ABURGER_HH__
# define __ABURGER_HH__

# include "ARecipe_CRTP.hpp"

template <typename T>
class ABurger : public ARecipe_CRTP<T>
{
public:
	enum TypeBurger {
		Royal = 1,
		Gourmand
	};

public:
	virtual ~ABurger() {}

protected:
	ABurger(enum ABurger::TypeBurger burgerType, const std::string & name, double cookingTime, enum ARecipe::TaillePizza size) : ARecipe_CRTP<T>(ARecipe::Burger, burgerType, "burger", name, cookingTime, size) {}
};

#endif /* !__ABURGER_HH__ */