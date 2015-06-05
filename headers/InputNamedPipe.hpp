/*
** InputNamedPipe.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:03:18 2015 nlequain
** Last update Sat Apr 25 19:31:28 2015 nlequain
*/

#ifndef __INPUTNAMEDPIPE_HH__
# define __INPUTNAMEDPIPE_HH__

# include <fstream>
# include "ANamedPipe.hpp"

class InputNamedPipe : public ANamedPipe
{
private:
	std::ifstream _stream;

public:
	InputNamedPipe(const std::string & name);
	virtual ~InputNamedPipe();

	virtual void open();
	virtual void close();

	void readLine(std::string & buffer);
	void operator>>(std::string & buffer);

	bool isEmpty();
};

#endif /* !__INPUTNAMEDPIPE_HH__ */