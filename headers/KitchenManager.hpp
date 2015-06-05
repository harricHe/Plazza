/*
** KitchenManager.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 14:49:08 2015 nlequain
** Last update Sun Apr 26 22:23:13 2015 nlequain
*/

#ifndef __KITCHENMANAGER_HH__
# define __KITCHENMANAGER_HH__

# include <list>
# include "Parser.hpp"
# include "Kitchen.hpp"
# include "ARecipe.hpp"
# include "RecipeFactory.hpp"
# include "IngredientFactory.hpp"
# include "KitchenTracker.hpp"
# include "AThreadable.hpp"
# include "IObserver.hpp"
# include "AObservable.hpp"

class Reception;

class KitchenManager : public AThreadable, public IObserver<KitchenTracker>, public AObservable<KitchenManager, Reception>
{
private: /* temporary data */
	KitchenTracker::KitchenMessage * _updateMessage;
	std::stringstream _errors;
	std::string _errorString;

private:
	RecipeFactory _recipeFactory;
	IngredientFactory _ingredientFactory;
	std::list<KitchenTracker *> _kitchens;
	double _timeMultiplier;
	size_t _cooksPerKitchen;
	int _freezerRefreshSpeed;

public:
	KitchenManager(double timeMultiplier, size_t cooksPerKitchen, int freezerRefreshSpeed, Reception * reception);
	~KitchenManager();
	bool treatOrder(Parser::Order & order);
	void run();
	void update(KitchenTracker * kitchenTracker);
	KitchenTracker::KitchenMessage * getUpdateMessage();
	const std::string & getError();

private:
	KitchenTracker * getLessBusyKitchen() const;
	ARecipe * orderToRecipe(Parser::Order & order);
};

#endif /* !__KITCHENMANAGER_HH__ */