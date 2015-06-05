/*
** Ham.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:59:45 2015 nlequain
** Last update Sun Apr 19 13:27:09 2015 nlequain
*/

#ifndef __HAM_HH__
# define __HAM_HH__

# include "AIngredient_CRTP.hpp"

class Ham : public AIngredient_CRTP<Ham>
{
public:
	Ham();
	~Ham();
};

#endif /* !__HAM_HH__ */
