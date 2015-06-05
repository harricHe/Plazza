/*
** NCursesIOManager.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 12:54:38 2015 nlequain
** Last update Sun Apr 26 23:36:46 2015 nlequain
*/

#ifndef __NCURSESIOMANAGER_HH__
# define __NCURSESIOMANAGER_HH__

# include <stdexcept>
# include <list>
# include <map>
# include <string>
# include <utility>
# include <sstream>
# include <ncurses.h>
# include "IngredientFactory.hpp"
# include "Reception.hpp"
# include "IObserver.hpp"
# include "IRunnable.hpp"

# define TIME_MULTIPLIER_MIN (0.1)
# define COOKS_PER_KITCHEN_MIN (1)
# define FREEZER_REFRESH_MIN (100)

class NCursesIOManager : public IRunnable, IObserver<Reception>
{
public:
	class NCursesException : public std::exception
	{
	protected:
	    const std::string _msg;
	    
	public:
	    NCursesException(const std::string msg) : _msg(msg) {};
	    ~NCursesException() throw() {};
	    const char * what() const throw() { return _msg.c_str(); }
	};

private:
	WINDOW * _window;
	bool _mustClose;
	IngredientFactory _ingredientFactory;
	Reception * _reception;
	std::list<std::string> _orderReadyList;
	std::map< int, std::pair < unsigned int, std::map < std::string, int > > > _kitchenData;
	std::string _errorString;

public:
	NCursesIOManager(const std::string & timeMultiplier, const std::string & cooksPerKitchen, const std::string & freezerRefreshSpeed);
	~NCursesIOManager();
	void init();
	void run();
	void destroy();
	void update(Reception * reception);

private:
	void writeOrdersReady() const;
	void writeKitchenData() const;
	void setupNewLine(std::stringstream & ss, int & positionX, int & positionY) const;
	void interpretChar(int c, std::string & input);

private: /* data interpreters */
	void recipeReady(Reception * reception);
	void fridgeUpdate(Reception * reception);
	void cookUpdate(Reception * reception);
	void closeKitchen(Reception * reception);

private: /* interpreters */
	void addCharToOrder(int c, std::string & input);
	void removeCharFromOrder(std::string & input);
	void sendInput(std::string & input);
	void handleWrongChar(std::string & input);
	void closeWindow(std::string & input);

private:
	template <typename T, typename U>
	U convertValue(const T & value) const
	{
		U convertedValue;
		std::stringstream valueConverter;

		valueConverter.clear();
		valueConverter << value;
		valueConverter >> convertedValue;
		return convertedValue;
	}
};

#endif /* !__NCURSESIOMANAGER_HH__ */