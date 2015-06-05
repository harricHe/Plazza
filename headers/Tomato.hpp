/*
** Tomato.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:12 2015 nlequain
*/

#ifndef __TOMATO_HH__
# define __TOMATO_HH__

# include "AIngredient_CRTP.hpp"

class Tomato : public AIngredient_CRTP<Tomato>
{
public:
	Tomato();
	~Tomato();
};

#endif /* !__TOMATO_HH__ */
