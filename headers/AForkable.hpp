/*
** AForkable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 23 16:46:47 2015 nlequain
** Last update Sun Apr 26 23:04:57 2015 nlequain
*/

#ifndef __AFORKABLE_HH__
# define __AFORKABLE_HH__

# include <stdexcept>
# include <string>
# include <sys/types.h>
# include "IRunnable.hpp"

class AForkable : public IRunnable
{
public:
	class ForkException : public std::exception
	{
	protected:
	    const std::string _msg;
	    
	public:
	    ForkException(const std::string msg) : _msg(msg) {};
	    ~ForkException() throw() {};
	    const char * what() const throw() { return _msg.c_str(); }
	};

private:
	pid_t _pid;

public:
	virtual ~AForkable();
	virtual void launchFork();
	virtual void stopFork();
};

#endif /* !__AFORKABLE_HH__ */