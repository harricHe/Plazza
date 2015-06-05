/*
** AForkable.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 23 17:24:40 2015 nlequain
** Last update Sun Apr 26 23:05:40 2015 nlequain
*/

#include <cstdlib>
#include <unistd.h>
#include <signal.h>
#include "AForkable.hpp"

AForkable::~AForkable()
{

}

void AForkable::launchFork()
{
	this->_pid = fork();
	if (this->_pid == -1)
		throw AForkable::ForkException("fork() failed");
	if (this->_pid == 0)
	{
		this->run();
		exit(EXIT_FAILURE);
	}
}

void AForkable::stopFork()
{
	kill(this->_pid, SIGTERM);
	this->_pid = 0;
}
