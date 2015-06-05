/*
** IRunnable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 16 23:01:09 2015 nlequain
** Last update Sun Apr 19 13:27:10 2015 nlequain
*/

#ifndef __IRUNNABLE_HH__
# define __IRUNNABLE_HH__

class IRunnable
{
public:
	virtual ~IRunnable() {}
	virtual void run() = 0;
};

#endif /* !__IRUNNABLE_HH__ */