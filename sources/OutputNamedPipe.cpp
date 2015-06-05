/*
** OutputNamedPipe.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:17:38 2015 nlequain
** Last update Sun Apr 26 23:04:12 2015 nlequain
*/

#include "OutputNamedPipe.hpp"

OutputNamedPipe::OutputNamedPipe(const std::string & name): ANamedPipe(name)
{

}

OutputNamedPipe::~OutputNamedPipe()
{

}

void OutputNamedPipe::open()
{
	this->_stream.open(this->getName().c_str());
	if (not this->_stream.is_open())
		throw ANamedPipe::NamedPipeException("open() failed on named pipe");
}

void OutputNamedPipe::close()
{
	this->_stream.close();
}

void OutputNamedPipe::write(const std::string & buffer)
{
	this->_stream << buffer << std::endl;
}

void OutputNamedPipe::operator<<(const std::string & buffer)
{
	this->write(buffer);
}
