/*
** ConditionalVariable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 17:19:13 2015 nlequain
** Last update Sun Apr 19 13:27:06 2015 nlequain
*/

#ifndef __CONDITIONALVARIABLE_HH__
# define __CONDITIONALVARIABLE_HH__

# include <pthread.h>
# include "Mutex.hpp"

class ConditionalVariable
{
private:
	pthread_cond_t _condvar;

public:
	ConditionalVariable();
	~ConditionalVariable();
	void sleep(Mutex & mutex);
	void wake();
};

#endif /* !__CONDITIONALVARIABLE_HH__ */