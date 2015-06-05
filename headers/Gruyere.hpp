/*
** Gruyere.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:09 2015 nlequain
*/

#ifndef __GRUYERE_HH__
# define __GRUYERE_HH__

# include "AIngredient_CRTP.hpp"

class Gruyere : public AIngredient_CRTP<Gruyere>
{
public:
	Gruyere();
	~Gruyere();
};

#endif /* !__GRUYERE_HH__ */
