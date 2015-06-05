/*
** GoatCheese.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:08 2015 nlequain
*/

#ifndef __GOATCHEESE_HH__
# define __GOATCHEESE_HH__

# include "AIngredient_CRTP.hpp"

class GoatCheese : public AIngredient_CRTP<GoatCheese>
{
public:
	GoatCheese();
	~GoatCheese();
};

#endif /* !__GOATCHEESE_HH__ */
