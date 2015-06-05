/*
** Americana.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:03:05 2015 nlequain
** Last update Thu Apr 23 11:10:37 2015 nlequain
*/

#ifndef __AMERICANA_HH__
# define __AMERICANA_HH__

# include "APizza.hpp"

class Americana : public APizza<Americana>
{
public:
	Americana(enum ARecipe::TaillePizza size = ARecipe::S);
	~Americana();
};

#endif /* !__AMERICANA_HH__ */