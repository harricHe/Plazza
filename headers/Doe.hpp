/*
** Doe.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:07 2015 nlequain
*/

#ifndef __DOE_HH__
# define __DOE_HH__

# include "AIngredient_CRTP.hpp"

class Doe : public AIngredient_CRTP<Doe>
{
public:
	Doe();
	~Doe();
};

#endif /* !__DOE_HH__ */
