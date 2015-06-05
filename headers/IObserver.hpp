/*
** IObserver.hpp for plazza in /home/kinoo_m/rendu/cpp_plazza
** 
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
** 
** Started on  Mon Apr 20 16:55:37 2015 Martin Kinoo
** Last update Mon Apr 20 19:00:22 2015 nlequain
*/

#ifndef __IOBSERVER_HH__
# define __IOBSERVER_HH__

template <typename T>
class		IObserver
{
public:
  virtual void update(T *) = 0;
  virtual ~IObserver() {};
};

#endif /* !__IOBSERVER_HH__ */