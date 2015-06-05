/*
** ARecipe_CRTP.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 11:01:05 2015 nlequain
** Last update Sat Apr 25 16:41:19 2015 nlequain
*/

#ifndef __ARECIPE_CRTP_HH__
# define __ARECIPE_CRTP_HH__

# include "ARecipe.hpp"
# include "ADuplicable.hpp"

template <typename T>
class ARecipe_CRTP : public ARecipe, public ADuplicable<T>
{
public:
	~ARecipe_CRTP() {}

protected:
	ARecipe_CRTP(enum ARecipe::TypeRecipe recipeType, int foodType, const std::string & recipeName, const std::string & name, double cookingTime, enum ARecipe::TaillePizza size) : ARecipe(recipeType, foodType, recipeName, name, cookingTime, size) {}
};

#endif /* !__ARECIPE_CRTP_HH__ */