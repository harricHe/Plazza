/*
** InputNamedPipe.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:17:19 2015 nlequain
** Last update Sun Apr 26 23:04:14 2015 nlequain
*/

#include "InputNamedPipe.hpp"

InputNamedPipe::InputNamedPipe(const std::string & name) : ANamedPipe(name)
{

}

InputNamedPipe::~InputNamedPipe()
{

}

void InputNamedPipe::open()
{
	this->_stream.open(this->getName().c_str());
	if (not this->_stream.is_open())
		throw ANamedPipe::NamedPipeException("open() failed on named pipe");
}

void InputNamedPipe::close()
{
	this->_stream.close();
}

void InputNamedPipe::readLine(std::string & buffer)
{
	std::getline(this->_stream, buffer);
}

void InputNamedPipe::operator>>(std::string & buffer)
{
	this->readLine(buffer);
}

bool InputNamedPipe::isEmpty()
{
	return (this->_stream.rdbuf()->in_avail() <= 0 ? true : false);
}
