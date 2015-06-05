/*
** IObservable.hpp for plazza in /home/kinoo_m/rendu/cpp_plazza
** 
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
** 
** Started on  Mon Apr 20 17:04:06 2015 Martin Kinoo
** Last update Mon Apr 20 19:01:54 2015 nlequain
*/

#ifndef __AOBSERVABLE_HH__
# define __AOBSERVABLE_HH__

template	<typename T, typename U>
class		AObservable
{
private:
  U * _observer;

public:
  virtual ~AObservable() {};

protected:
  AObservable(U * observer) : _observer(observer) {}

  virtual void notify() { this->_observer->update(dynamic_cast<T *>(this)); };
  U & getObserver() { return *this->_observer; }
};

#endif /* !__AOBSERVABLE_HH__ */