/*
** Margarita.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:03:05 2015 nlequain
** Last update Thu Apr 23 11:10:33 2015 nlequain
*/

#ifndef __MARGARITA_HH__
# define __MARGARITA_HH__

# include "APizza.hpp"

class Margarita : public APizza<Margarita>
{
public:
	Margarita(enum ARecipe::TaillePizza size = ARecipe::S);
	~Margarita();
};

#endif /* !__MARGARITA_HH__ */