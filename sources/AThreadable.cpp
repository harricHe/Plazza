/*
** AThreadable.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 16 23:09:04 2015 nlequain
** Last update Sun Apr 26 23:08:21 2015 nlequain
*/

#include <cstdlib>
#include "AThreadable.hpp"

AThreadable::~AThreadable()
{

}

void AThreadable::launchThread()
{
	if (pthread_create(&this->_thread, NULL, AThreadable::execute, (void *)this))
		throw AThreadable::ThreadException("pthread_create() failed");
}

void AThreadable::stopThread()
{
	if (pthread_cancel(this->_thread) != 0)
		throw AThreadable::ThreadException("pthread_cancel() failed");
}

void * AThreadable::execute(void *object)
{
	IRunnable * self = reinterpret_cast<IRunnable *>(object);
	self->run();
	return (NULL);
}