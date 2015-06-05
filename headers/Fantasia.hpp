/*
** Fantasia.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:03:05 2015 nlequain
** Last update Thu Apr 23 11:10:39 2015 nlequain
*/

#ifndef __FANTASIA_HH__
# define __FANTASIA_HH__

# include "APizza.hpp"

class Fantasia : public APizza<Fantasia>
{
public:
	Fantasia(enum ARecipe::TaillePizza size = ARecipe::S);
	~Fantasia();
};

#endif /* !__FANTASIA_HH__ */