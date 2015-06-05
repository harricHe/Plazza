/*
** OutputNamedPipe.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:08:23 2015 nlequain
** Last update Sat Apr 25 15:52:39 2015 nlequain
*/

#ifndef __OUTPUTNAMEDPIPE_HH__
# define __OUTPUTNAMEDPIPE_HH__

# include <fstream>
# include "ANamedPipe.hpp"

class OutputNamedPipe : public ANamedPipe
{
private:
	std::ofstream _stream;

public:
	OutputNamedPipe(const std::string & name);
	virtual ~OutputNamedPipe();

	virtual void open();
	virtual void close();

	void write(const std::string & buffer);
	void operator<<(const std::string & buffer);
};

#endif /* !__OUTPUTNAMEDPIPE_HH__ */