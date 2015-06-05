/*
** Cook.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 15:27:48 2015 nlequain
** Last update Sun Apr 26 11:38:54 2015 nlequain
*/

#ifndef __COOK_HH__
# define __COOK_HH__

# include "AThreadable.hpp"
# include "AObservable.hpp"
# include "ARecipe.hpp"

class Kitchen;

class Cook : public AThreadable, public AObservable<Cook, Kitchen>
{
private:
	ARecipe * _commandToCook;
	double _timeMultiplier;

public:
	Cook(double timeMultiplier, Kitchen * kitchen);
	~Cook();

	void run();
	void setCommand(ARecipe * command);
	ARecipe * sendCommand();
};

#endif /* !__COOK_HH__ */
