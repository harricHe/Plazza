/*
** ANamedPipe.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 13:59:03 2015 nlequain
** Last update Sun Apr 26 23:04:18 2015 nlequain
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ANamedPipe.hpp"

ANamedPipe::ANamedPipe(const std::string & name) : _name(name)
{

}

ANamedPipe::~ANamedPipe()
{

}

void ANamedPipe::create()
{
  if (mkfifo(this->_name.c_str(), 0666) == -1)
  	throw ANamedPipe::NamedPipeException("mkfifo() failed");
}

void ANamedPipe::destroy()
{
  if (unlink(this->_name.c_str()) == -1)
  	throw ANamedPipe::NamedPipeException("unlink() failed");
}

const std::string & ANamedPipe::getName() const
{
	return this->_name;
}
