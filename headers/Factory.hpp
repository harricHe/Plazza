/*
** Factory.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 18 10:06:56 2015 nlequain
** Last update Sun Apr 26 19:16:05 2015 nlequain
*/

#ifndef __FACTORY_HH__
# define __FACTORY_HH__

# include <cstdlib>
# include <map>

template <typename T, typename U>
class Factory
{
private:
	std::map<T, U *> _models;

public:
	Factory() {}

	virtual ~Factory()
	{
		for (typename std::map<T, U *>::iterator model = this->_models.begin(); model != this->_models.end(); ++model)
			delete model->second;
	}

	virtual void addModel(const T & identifier, U * model)
	{
		if (this->_models.find(identifier) == this->_models.end())
			this->_models[identifier] = model;
	}

	virtual U * create(const T & identifier)
	{
		if (this->_models.find(identifier) == this->_models.end())
			return NULL;
		return dynamic_cast<U *>(this->_models[identifier]->duplicate());
	}
};

#endif /* !__FACTORY_HH__ */