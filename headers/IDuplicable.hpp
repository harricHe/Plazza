/*
** IDuplicable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 11:50:42 2015 nlequain
** Last update Thu Apr 23 11:04:24 2015 nlequain
*/

#ifndef __IDUPLICABLE_HH__
# define __IDUPLICABLE_HH__

class IDuplicable
{
public:
	virtual ~IDuplicable() {}
	virtual IDuplicable * duplicate() const = 0;
};

#endif /* !__IDUPLICABLE_HH__ */