/*
** AFood.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 19:09:50 2015 nlequain
** Last update Sun Apr 26 15:32:04 2015 nlequain
*/

#ifndef __AFOOD_HH__
# define __AFOOD_HH__

# include <unistd.h>
# include <string>
# include <iostream>
# include "ADecorable.hpp"

template <typename T>
class AFood : public ADecorable<T>
{
private:
	std::string _name;
	int _cookingTime;

public:
	virtual ~AFood() {}
	const std::string & getName() const { return this->_name; }

	int getCookingTime() const
	{
		int cookingTime = this->getThisCookingTime();
		if (this->_decorator)
			cookingTime += this->_decorator->getCookingTime();
		return cookingTime;
	}

	void cook(double timeMultiplier) const
	{
		usleep(this->getCookingTime() * timeMultiplier);
	}

protected:
	AFood(const std::string & name, double cookingTime) : _name(name), _cookingTime(cookingTime * 1000000) {}

	virtual int getThisCookingTime() const
	{
		return this->_cookingTime;
	}
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const AFood<T> & food)
{
	os << food.getName();
	if (food.getDecorator())
		os << *(food.getDecorator());
	return os;
}

#endif /* !__AFOOD_HH__ */
