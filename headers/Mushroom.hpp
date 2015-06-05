/*
** Mushroom.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:10 2015 nlequain
*/

#ifndef __MUSHROOM_HH__
# define __MUSHROOM_HH__

# include "AIngredient_CRTP.hpp"

class Mushroom : public AIngredient_CRTP<Mushroom>
{
public:
	Mushroom();
	~Mushroom();
};

#endif /* !__MUSHROOM_HH__ */
