/*
** ANamedPipe.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 13:55:55 2015 nlequain
** Last update Sun Apr 26 23:02:14 2015 nlequain
*/

#ifndef __ANAMEDPIPE_HH__
# define __ANAMEDPIPE_HH__

# include <stdexcept>
# include <string>

class ANamedPipe
{
public:
	class NamedPipeException : public std::exception
	{
	protected:
	    const std::string _msg;
	    
	public:
	    NamedPipeException(const std::string msg) : _msg(msg) {};
	    ~NamedPipeException() throw() {};
	    const char * what() const throw() { return _msg.c_str(); }
	};

private:
	std::string _name;

public:
	ANamedPipe(const std::string & name);
	virtual ~ANamedPipe();

	void create();
	void destroy();

	virtual void open() = 0;
	virtual void close() = 0;

	const std::string & getName() const;
};

#endif /* !__ANAMEDPIPE_HH__ */