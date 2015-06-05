/*
** MutexScopedLock.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 14:23:36 2015 nlequain
** Last update Sun Apr 19 14:28:20 2015 nlequain
*/

#ifndef __MUTEXSCOPEDLOCK_HH__
# define __MUTEXSCOPEDLOCK_HH__

# include "Mutex.hpp"

class MutexScopedLock
{
private:
	Mutex & _mutex;

public:
	MutexScopedLock(Mutex & mutex);
	~MutexScopedLock();
};

#endif /* !__MUTEXSCOPEDLOCK_HH__ */