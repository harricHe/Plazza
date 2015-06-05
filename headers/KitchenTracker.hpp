/*
** KitchenTracker.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 20:22:47 2015 nlequain
** Last update Sun Apr 26 17:38:54 2015 nlequain
*/

#ifndef __KITCHENTRACKER_HH__
# define __KITCHENTRACKER_HH__

# include <string>
# include "Kitchen.hpp"
# include "InputNamedPipe.hpp"
# include "OutputNamedPipe.hpp"
# include "AThreadable.hpp"
# include "AObservable.hpp"
# include "Mutex.hpp"

# define NAMED_PIPE_BASE_NAME "plazzafifo"

class KitchenManager;

class KitchenTracker : public AThreadable, public AObservable<KitchenTracker, KitchenManager>
{
public:
	class KitchenMessage
	{
	private:
		int _kitchenId;
		ASerializable::DataType _messageType;
		std::string _message;
	public:
		KitchenMessage(int kitchenId);
		~KitchenMessage();
		int getKitchenId() const;
		ASerializable::DataType getMessageType() const;
		const std::string & getMessage() const;
		void setMessage(const std::string & message);
		void setMessageType(ASerializable::DataType messageType);
	};

private: /* static data */
	static Mutex _outputMutex;
	static size_t _kitchenId;

private: /* class data */
	Kitchen * _kitchen;
	OutputNamedPipe * _pipeToKitchen;
	InputNamedPipe * _pipeFromKitchen;
	size_t _orderCount;
	bool _mustClose;

private: /* temporary data */
	KitchenTracker::KitchenMessage * _updateMessage;

public:
	KitchenTracker(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, KitchenManager * manager);
	~KitchenTracker();

	void run();

	void operator<<(const std::string & order); //data sending
	void operator>>(std::string & order); //data reception

	void addOrder();
	void removeOrder();

	size_t getOrderCount() const;
	bool mustClose() const;
	KitchenTracker::KitchenMessage * getUpdateMessage();
};

#endif /* !__KITCHENTRACKER_HH__ */