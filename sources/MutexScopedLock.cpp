/*
** MutexScopedLock.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 14:25:36 2015 nlequain
** Last update Sun Apr 19 18:13:04 2015 nlequain
*/

#include "MutexScopedLock.hpp"

MutexScopedLock::MutexScopedLock(Mutex & mutex) : _mutex(mutex)
{
	this->_mutex.lock();
}

MutexScopedLock::~MutexScopedLock()
{
	this->_mutex.unlock();
}
