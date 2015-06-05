/*
** Mutex.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 13:32:31 2015 nlequain
** Last update Sun Apr 19 13:27:11 2015 nlequain
*/

#ifndef __MUTEX_HH__
# define __MUTEX_HH__

# include <pthread.h>

class Mutex
{
private:
	pthread_mutex_t _mutex;

public:
	Mutex();
	~Mutex();
	void lock();
	void unlock();
	pthread_mutex_t * getMutex();
};

#endif /* !__MUTEX_HH__ */