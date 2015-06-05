/*
** Gourmand.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 22:40:24 2015 nlequain
** Last update Sun Apr 26 22:41:47 2015 nlequain
*/

#ifndef __GOURMAND_HH__
# define __GOURMAND_HH__

# include "ABurger.hpp"

class Gourmand : public ABurger<Gourmand>
{
public:
	Gourmand(enum ARecipe::TaillePizza size = ARecipe::S);
	~Gourmand();
};

#endif /* !__GOURMAND_HH__ */