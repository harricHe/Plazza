/*
** ADecorable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 18:55:42 2015 nlequain
** Last update Sun Apr 26 09:46:49 2015 nlequain
*/

#ifndef __ADECORABLE_HH__
# define __ADECORABLE_HH__

# include <cstdlib>

template <typename T>
class ADecorable
{
protected:
	T * _decorator;

public:
	virtual ~ADecorable()
	{
		if (this->_decorator)
			delete this->_decorator;		
	}

	virtual void addDecorator(T * decorator)
	{
		if (not this->_decorator)
			this->_decorator = decorator;
		else
			this->_decorator->addDecorator(decorator);
	}

	const T * getDecorator() const
	{
		return this->_decorator;
	}

protected:
	ADecorable() : _decorator(NULL) {}
};

#endif /* !__ADECORABLE_HH__ */