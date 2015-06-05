/*
** NCursesIOManager.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 12:54:56 2015 nlequain
** Last update Sun Apr 26 23:36:32 2015 nlequain
*/

#include <iostream>
#include <map>
#include <cctype>
#include "Doe.hpp"
#include "Eggplant.hpp"
#include "GoatCheese.hpp"
#include "Gruyere.hpp"
#include "Ham.hpp"
#include "Mushroom.hpp"
#include "Steak.hpp"
#include "Tomato.hpp"
#include "NCursesIOManager.hpp"

NCursesIOManager::NCursesIOManager(const std::string & timeMultiplier, const std::string & cooksPerKitchen, const std::string & freezerRefreshSpeed) : _mustClose(false)
{
	double timeMultiplierValue = this->convertValue<std::string, double>(timeMultiplier);
	int cooksPerKitchenValue = this->convertValue<std::string, int>(cooksPerKitchen);
	int freezerRefreshSpeedValue = this->convertValue<std::string, int>(freezerRefreshSpeed);


	if (timeMultiplierValue <= TIME_MULTIPLIER_MIN)
		timeMultiplierValue = TIME_MULTIPLIER_MIN;
	if (cooksPerKitchenValue <= COOKS_PER_KITCHEN_MIN)
		cooksPerKitchenValue = COOKS_PER_KITCHEN_MIN;
	if (freezerRefreshSpeedValue <= FREEZER_REFRESH_MIN)
		freezerRefreshSpeedValue = FREEZER_REFRESH_MIN;
	this->_reception = new Reception(timeMultiplierValue, cooksPerKitchenValue, freezerRefreshSpeedValue, this);
	this->_ingredientFactory.addModel(new Doe());
	this->_ingredientFactory.addModel(new Eggplant());
	this->_ingredientFactory.addModel(new GoatCheese());
	this->_ingredientFactory.addModel(new Gruyere());
	this->_ingredientFactory.addModel(new Ham());
	this->_ingredientFactory.addModel(new Mushroom());
	this->_ingredientFactory.addModel(new Steak());
	this->_ingredientFactory.addModel(new Tomato());
}

NCursesIOManager::~NCursesIOManager()
{
	delete this->_reception;
}

void NCursesIOManager::init()
{
	this->_window = initscr();
	if (not this->_window)
		throw NCursesIOManager::NCursesException("initscr() failed");
	timeout(0.1 * 1000);
	(void)cbreak();
	if (keypad(this->_window, TRUE) == ERR)
		throw NCursesIOManager::NCursesException("keypad() failed");
}

void NCursesIOManager::destroy()
{
	keypad(this->_window, FALSE);
	(void)nocbreak();
	timeout(-1);
	(void)endwin();
}

/*
** Pattern Observer
*/

void NCursesIOManager::update(Reception * reception)
{
	std::map<ASerializable::DataType, void (NCursesIOManager::*)(Reception *)> dataInterpreter;

	dataInterpreter[ASerializable::Recipe] = &NCursesIOManager::recipeReady;
	dataInterpreter[ASerializable::Fridge] = &NCursesIOManager::fridgeUpdate;
	dataInterpreter[ASerializable::Cook] = &NCursesIOManager::cookUpdate;
	dataInterpreter[ASerializable::KitchenClosing] = &NCursesIOManager::closeKitchen;

	if (this->_kitchenData.find(reception->getUpdateMessage()->getKitchenId()) == this->_kitchenData.end())
		this->_kitchenData[reception->getUpdateMessage()->getKitchenId()].first = 0;
	if (dataInterpreter.find(reception->getUpdateMessage()->getMessageType()) != dataInterpreter.end())
		(this->*dataInterpreter[reception->getUpdateMessage()->getMessageType()])(reception);
}

void NCursesIOManager::recipeReady(Reception * reception)
{
	const size_t maxOrdersStored = 15;

	this->_orderReadyList.push_back(reception->getUpdateMessage()->getMessage());
	if (this->_orderReadyList.size() > maxOrdersStored)
		this->_orderReadyList.pop_front();
}

void NCursesIOManager::fridgeUpdate(Reception * reception)
{
	Freezer::SerializableFreezer serializableFreezer;

	serializableFreezer.unpack(reception->getUpdateMessage()->getMessage());
	for (std::map<AIngredient::TypeIngredient, unsigned int>::const_iterator ingredient = serializableFreezer.getIngredientStock().begin(); ingredient != serializableFreezer.getIngredientStock().end(); ++ingredient)
	{
		std::string * ingredientName = this->_ingredientFactory.getIngredientName(ingredient->first);
		if (ingredientName != NULL)
		{
			this->_kitchenData[reception->getUpdateMessage()->getKitchenId()].second[*ingredientName] = ingredient->second;
			delete ingredientName;
		}
	}
}

void NCursesIOManager::cookUpdate(Reception * reception)
{
	this->_kitchenData[reception->getUpdateMessage()->getKitchenId()].first += this->convertValue<std::string, int>(reception->getUpdateMessage()->getMessage());
}

void NCursesIOManager::closeKitchen(Reception * reception)
{
	this->_kitchenData.erase(reception->getUpdateMessage()->getKitchenId());
}

/*
** Running
*/

void NCursesIOManager::run()
{
	std::string input;
	std::string commandLineMessage = "Type your order : ";
	int c;

	while (this->_mustClose == false)
	{
		erase();
		move(0, 0);
		printw(commandLineMessage.c_str());
		printw(input.c_str());
		move(1, 0);
		printw(this->_errorString.c_str());
		this->writeOrdersReady();
		this->writeKitchenData();
		if (refresh() == ERR)
			throw NCursesIOManager::NCursesException("refresh() failed");
		move(0, commandLineMessage.length() + input.length());
		c = getch();
		this->interpretChar(c, input);
	}
}

void NCursesIOManager::writeOrdersReady() const
{
	int positionY = 3;

	for (std::list<std::string>::const_iterator order = this->_orderReadyList.begin(); order != this->_orderReadyList.end(); ++order)
	{
		move(positionY, 0);
		printw("Command ready : ");
		printw(order->c_str());
		++positionY;
	}
}

void NCursesIOManager::writeKitchenData() const
{
	int maxX, maxY;
	int initialPositionY = 20;
	int positionX = 0;
	std::stringstream output;

	getmaxyx(this->_window, maxY, maxX);
	/* iterates through every kitchen */
	for (std::map< int, std::pair < unsigned int, std::map < std::string, int > > >::const_iterator kitchen = this->_kitchenData.begin(); kitchen != this->_kitchenData.end(); ++kitchen)
	{
		int positionY = initialPositionY;
		size_t maxLenght = 0;

		/* displays kitchen identifier */
		this->setupNewLine(output, positionX, positionY);
		output << "[Kitchen " << kitchen->first << "]";
		printw(output.str().c_str());
		if (maxLenght < output.str().length())
			maxLenght = output.str().length();
		/* displays cooks activity */
		this->setupNewLine(output, positionX, positionY);
		output << "Active cooks : " << kitchen->second.first;
		printw(output.str().c_str());
		if (maxLenght < output.str().length())
			maxLenght = output.str().length();
		/* displays fridge ingredients */
		for (std::map<std::string, int>::const_iterator ingredient = kitchen->second.second.begin(); ingredient != kitchen->second.second.end(); ++ingredient)
		{
			this->setupNewLine(output, positionX, positionY);
			output << ingredient->first << " : " << ingredient->second;
			printw(output.str().c_str());
			if (maxLenght < output.str().length())
				maxLenght = output.str().length();
		}
		/* manages window size */
		positionX += maxLenght + 3;
		if (positionX + maxLenght > static_cast<size_t>(maxX))
		{
			positionX = 0;
			if (positionY + (positionY - initialPositionY) + 1 > maxY)
				return;
			initialPositionY = positionY + 1;
		}
	}
}

void NCursesIOManager::setupNewLine(std::stringstream & ss, int & positionX, int & positionY) const
{
	move(positionY, positionX);
	++positionY;
	ss.clear();
	ss.str("");
}

/*
** Interpret char
*/

void NCursesIOManager::interpretChar(int c, std::string & input)
{
	std::map<int, void (NCursesIOManager::*)(std::string &)> interpreter;

	interpreter[ERR] = &NCursesIOManager::handleWrongChar;
	interpreter[KEY_BACKSPACE] = &NCursesIOManager::removeCharFromOrder;
	interpreter['\n'] = &NCursesIOManager::sendInput;
	interpreter[27/*escape key*/] = &NCursesIOManager::closeWindow;

	if (interpreter.find(c) != interpreter.end())
		(this->*interpreter[c])(input);
	else
		this->addCharToOrder(c, input);

}

void NCursesIOManager::addCharToOrder(int c, std::string & input)
{
	input.push_back(c);
}

void NCursesIOManager::removeCharFromOrder(std::string & input)
{
	input.resize(input.length() == 0 ? 0 : input.length() - 1);
}

void NCursesIOManager::sendInput(std::string & input)
{
	this->_reception->orderIn(input);
	this->_errorString = this->_reception->getError();
	input.clear();
}

void NCursesIOManager::handleWrongChar(std::string & input)
{
	(void)input;
}

void NCursesIOManager::closeWindow(std::string & input)
{
	(void)input;
	this->_mustClose = true;
}