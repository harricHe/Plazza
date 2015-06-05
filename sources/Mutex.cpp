/*
** Mutex.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 16:42:33 2015 nlequain
** Last update Sun Apr 19 18:13:02 2015 nlequain
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
	(void)pthread_mutex_init(&this->_mutex, NULL);
}

Mutex::~Mutex()
{
	(void)pthread_mutex_destroy(&this->_mutex);
}

void Mutex::lock()
{
	(void)pthread_mutex_lock(&this->_mutex);	
}

void Mutex::unlock()
{
	(void)pthread_mutex_unlock(&this->_mutex);
}

pthread_mutex_t * Mutex::getMutex()
{
	return &this->_mutex;
}
