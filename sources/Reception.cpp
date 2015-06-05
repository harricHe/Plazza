/*
** Reception.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 16:09:47 2015 nlequain
** Last update Sun Apr 26 22:23:20 2015 nlequain
*/

#include "Reception.hpp"
#include "NCursesIOManager.hpp"

Reception::Reception(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, NCursesIOManager * ioManager) : AObservable(ioManager)
{
	this->_kitchenManager = new KitchenManager(timeMultiplier, cooksPerKitchen, freezerRefreshSpeed, this);
	this->_logFile.open(LOG_FILE_NAME, std::fstream::out | std::fstream::in | std::fstream::app);
}

Reception::~Reception()
{
	delete this->_kitchenManager;
}

void Reception::orderIn(const std::string & order)
{
	std::list<Parser::Order> * orders;

	this->_logFile << "[IN]" << "\t" << order << std::endl;

	orders = this->_parser.parseOrder(order);
	for (std::list<Parser::Order>::iterator it = orders->begin(); it != orders->end(); ++it)
		this->_kitchenManager->treatOrder(*it);
}

void Reception::update(KitchenManager * kitchenManager)
{
	this->_updateMessage = kitchenManager->getUpdateMessage();
	if (this->_updateMessage->getMessageType() == ASerializable::Recipe)
		this->_logFile << "[OUT]" << "\t" << this->_updateMessage->getMessage() << std::endl;
	this->notify();
}

KitchenTracker::KitchenMessage * Reception::getUpdateMessage()
{
	return this->_updateMessage;
}

const std::string & Reception::getError()
{
	std::stringstream errorStream("");

	errorStream << this->_parser.getError();
	errorStream << this->_kitchenManager->getError();
	this->_errorString = errorStream.str();
	return this->_errorString;
}