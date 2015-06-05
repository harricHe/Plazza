/*
** AThreadable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 16 23:06:52 2015 nlequain
** Last update Sun Apr 26 23:07:07 2015 nlequain
*/

#ifndef __ATHREADABLE_HH__
# define __ATHREADABLE_HH__

# include <stdexcept>
# include <string>
# include <pthread.h>
# include "IRunnable.hpp"

class AThreadable : public IRunnable
{
public:
	class ThreadException : public std::exception
	{
	protected:
	    const std::string _msg;
	    
	public:
	    ThreadException(const std::string msg) : _msg(msg) {};
	    ~ThreadException() throw() {};
	    const char * what() const throw() { return _msg.c_str(); }
	};

private:
	pthread_t _thread;

public:
	virtual ~AThreadable();
	virtual void launchThread();
	virtual void stopThread();

private:
	static void * execute(void *object);
};

#endif /* !__ATHREADABLE_HH__ */