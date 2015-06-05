/*
** Regina.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:03:05 2015 nlequain
** Last update Thu Apr 23 11:10:35 2015 nlequain
*/

#ifndef __REGINA_HH__
# define __REGINA_HH__

# include "APizza.hpp"

class Regina : public APizza<Regina>
{
public:
	Regina(enum ARecipe::TaillePizza size = ARecipe::S);
	~Regina();
};

#endif /* !__REGINA_HH__ */