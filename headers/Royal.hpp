/*
** Royal.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 22:36:57 2015 nlequain
** Last update Sun Apr 26 22:40:32 2015 nlequain
*/

#ifndef __ROYAL_HH__
# define __ROYAL_HH__

# include "ABurger.hpp"

class Royal : public ABurger<Royal>
{
public:
	Royal(enum ARecipe::TaillePizza size = ARecipe::S);
	~Royal();
};

#endif /* !__ROYAL_HH__ */