/*
** AIngredient_CRTP.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 12:36:52 2015 nlequain
** Last update Mon Apr 20 12:35:53 2015 nlequain
*/

#ifndef __AINGREDIENT_CRTP_HH__
# define __AINGREDIENT_CRTP_HH__

# include "AIngredient.hpp"
# include "ADuplicable.hpp"

template <typename T>
class AIngredient_CRTP : public AIngredient, public ADuplicable<T>
{
public:
	virtual ~AIngredient_CRTP() {}

protected:
	AIngredient_CRTP(enum AIngredient::TypeIngredient ingredientType, const std::string & name, double cookingTime) : AIngredient(ingredientType, name, cookingTime) {};
};

#endif /* !__AINGREDIENT_CRTP_HH__ */