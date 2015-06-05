/*
** ADuplicable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 10:51:46 2015 nlequain
** Last update Sun Apr 19 13:27:04 2015 nlequain
*/

#ifndef __ADUPLICABLE_HH__
# define __ADUPLICABLE_HH__

# include "IDuplicable.hpp"

template <typename T>
class ADuplicable : virtual public IDuplicable
{
public:
	virtual ~ADuplicable() {}

	virtual IDuplicable * duplicate() const
	{
		return new T();
	}

protected:
	ADuplicable() {}
};

#endif /* !__ADUPLICABLE_HH__ */