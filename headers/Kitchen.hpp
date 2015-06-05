/*
** Kitchen.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 19 15:27:21 2015 nlequain
** Last update Sun Apr 26 20:43:07 2015 nlequain
*/

#ifndef __KITCHEN_HH__
# define __KITCHEN_HH__

# include <list>
# include <queue>
# include <fstream>
# include <string>
# include "AForkable.hpp"
# include "IObserver.hpp"
# include "ConditionalVariable.hpp"
# include "Mutex.hpp"
# include "Freezer.hpp"
# include "ARecipe.hpp"
# include "Cook.hpp"
# include "RecipeFactory.hpp"
# include "InputNamedPipe.hpp"
# include "OutputNamedPipe.hpp"

class Kitchen : public AForkable, public IObserver<Cook>, public IObserver<Freezer>
{
private:
	std::string _namedPipeFromReception, _namedPipeToReception;

private:
	RecipeFactory _recipeFactory;
	std::list<Cook> _cooks;
	std::queue<ARecipe *> _commandList;
	Freezer * _freezer;
	ConditionalVariable _commandWaiter;
	Mutex _commandMutex;
	Mutex _outputMutex;
	OutputNamedPipe * _pipeToReception;
	InputNamedPipe * _pipeFromReception;

public:
	Kitchen(double timeMultiplier, size_t cooksNumber, unsigned int freezerRefreshSpeed, const std::string & namedPipeFromReception, const std::string & namedPipeToReception);
	~Kitchen();

	void run();
	void update(Cook * cook);
	void update(Freezer * freezer);
	AIngredient * getIngredientFromFreezer(AIngredient::TypeIngredient ingredientType);

private:
	void launchThreads();
	void stopThreads();
	void addCommand(ARecipe * command);
	void sendCookBusyNotification(int modifier);
};

#endif /* !__KITCHEN_HH__ */