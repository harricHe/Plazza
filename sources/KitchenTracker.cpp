/*
** KitchenTracker.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 20:24:44 2015 nlequain
** Last update Sun Apr 26 21:22:17 2015 nlequain
*/

#include <sstream>
#include "KitchenTracker.hpp"
#include "KitchenManager.hpp"

/*
** KitchenTracker
*/

size_t KitchenTracker::_kitchenId = 0;
Mutex KitchenTracker::_outputMutex = Mutex();

KitchenTracker::KitchenTracker(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, KitchenManager * manager) : AObservable(manager), _orderCount(0), _mustClose(false)
{
	std::stringstream fifoNameOut;
	std::stringstream fifoNameIn;

	this->_updateMessage = new KitchenTracker::KitchenMessage(this->_kitchenId);
	fifoNameOut << NAMED_PIPE_BASE_NAME << "out" << this->_kitchenId;
	fifoNameIn << NAMED_PIPE_BASE_NAME << "in" << this->_kitchenId;
	++this->_kitchenId;
	this->_pipeToKitchen = new OutputNamedPipe(fifoNameOut.str());
	this->_pipeFromKitchen = new InputNamedPipe(fifoNameIn.str());
	this->_pipeToKitchen->create();
	this->_pipeFromKitchen->create();
	this->_kitchen = new Kitchen(timeMultiplier, cooksPerKitchen, freezerRefreshSpeed, this->_pipeToKitchen->getName(), this->_pipeFromKitchen->getName());
	this->_kitchen->launchFork();
	this->_pipeToKitchen->open();
	this->_pipeFromKitchen->open();
	this->launchThread();
}

KitchenTracker::~KitchenTracker()
{
	this->stopThread();
	this->_kitchen->stopFork();
	delete this->_kitchen;
	this->_pipeToKitchen->close();
	this->_pipeToKitchen->destroy();
	delete this->_pipeToKitchen;
	this->_pipeFromKitchen->close();
	this->_pipeFromKitchen->destroy();
	delete this->_pipeFromKitchen;
}

void KitchenTracker::run()
{
	int timeWithoutMessage = 0;
	double refreshSpeed = 0.1;
	double timeBeforeClosing = 5;
	bool inactive;

	while (true)
	{
		inactive = true;
		while (not this->_pipeFromKitchen->isEmpty())
		{
			std::string message;

			*this >> message;
			this->_updateMessage->setMessageType(ASerializable::getType(message));
			this->_updateMessage->setMessage(message);
			if (this->_updateMessage->getMessageType() == ASerializable::Recipe)
			{
				this->removeOrder();
				inactive = false;
			}
			this->_outputMutex.lock();
			this->notify();
			this->_outputMutex.unlock();
		}
		if (inactive == true)
			timeWithoutMessage += refreshSpeed * 1000000;
		else
			timeWithoutMessage = 0;
		if (timeWithoutMessage >= timeBeforeClosing * 1000000)
		{
			this->_updateMessage->setMessageType(ASerializable::KitchenClosing);
			this->_outputMutex.lock();
			this->notify();
			this->_outputMutex.unlock();
			this->_mustClose = true;
		}
		usleep(refreshSpeed * 1000000);
	}
}

void KitchenTracker::operator<<(const std::string & order)
{
	*this->_pipeToKitchen << order;
}

void KitchenTracker::operator>>(std::string & order)
{
	*this->_pipeFromKitchen >> order;
}

void KitchenTracker::addOrder()
{
	++this->_orderCount;
}

void KitchenTracker::removeOrder()
{
	--this->_orderCount;
}

size_t KitchenTracker::getOrderCount() const
{
	return this->_orderCount;
}

bool KitchenTracker::mustClose() const
{
	return this->_mustClose;
}

KitchenTracker::KitchenMessage * KitchenTracker::getUpdateMessage()
{
	return this->_updateMessage;
}

/*
** KitchenData
*/

KitchenTracker::KitchenMessage::KitchenMessage(int kitchenId) : _kitchenId(kitchenId)
{

}

KitchenTracker::KitchenMessage::~KitchenMessage()
{

}

int KitchenTracker::KitchenMessage::getKitchenId() const
{
	return this->_kitchenId;
}

ASerializable::DataType KitchenTracker::KitchenMessage::getMessageType() const
{
	return this->_messageType;
}

const std::string & KitchenTracker::KitchenMessage::getMessage() const
{
	return this->_message;
}

void KitchenTracker::KitchenMessage::setMessage(const std::string & message)
{
	this->_message = message;
}

void KitchenTracker::KitchenMessage::setMessageType(ASerializable::DataType messageType)
{
	this->_messageType = messageType;
}