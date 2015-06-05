/*
** ConditionalVariable.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 17:30:09 2015 nlequain
** Last update Sun Apr 19 17:45:46 2015 nlequain
*/

#include "ConditionalVariable.hpp"

ConditionalVariable::ConditionalVariable()
{
	(void)pthread_cond_init(&this->_condvar, NULL);
}

ConditionalVariable::~ConditionalVariable()
{
	(void)pthread_cond_destroy(&this->_condvar);
}

void ConditionalVariable::sleep(Mutex & mutex)
{
	(void)pthread_cond_wait(&this->_condvar, mutex.getMutex());
}

void ConditionalVariable::wake()
{
	(void)pthread_cond_broadcast(&this->_condvar);
}
