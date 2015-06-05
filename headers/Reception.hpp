/*
** Reception.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 16:06:03 2015 nlequain
** Last update Sun Apr 26 22:23:18 2015 nlequain
*/

#ifndef __RECEPTION_HH__
# define __RECEPTION_HH__

# include <fstream>
# include <string>
# include <sstream>
# include "Parser.hpp"
# include "KitchenManager.hpp"
# include "IObserver.hpp"
# include "AObservable.hpp"

# define LOG_FILE_NAME "plazza.log"

class NCursesIOManager;

class Reception : public IObserver<KitchenManager>, public AObservable<Reception, NCursesIOManager>
{
private: /* temporary data */
	KitchenTracker::KitchenMessage * _updateMessage;
	std::string _errorString;

private:
	std::fstream _logFile;
	Parser _parser;
	KitchenManager * _kitchenManager;

public:
	Reception(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, NCursesIOManager * ioManager);
	~Reception();

	void orderIn(const std::string & order);
	void update(KitchenManager * kitchenManager);

	KitchenTracker::KitchenMessage * getUpdateMessage();
	const std::string & getError();
};

#endif /* !__RECEPTION_HH__ */