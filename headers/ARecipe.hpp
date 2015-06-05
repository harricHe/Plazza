/*
** ARecipe.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 20:12:15 2015 nlequain
** Last update Sun Apr 26 22:35:44 2015 nlequain
*/

#ifndef __ARECIPE_HH__
# define __ARECIPE_HH__

# include <list>
# include <string>
# include "AFood.hpp"
# include "AIngredient.hpp"
# include "IDuplicable.hpp"
# include "ASerializable.hpp"

class ARecipe : public AFood<AIngredient>, virtual public IDuplicable
{
public:
	enum TypeRecipe {
		Pizza = 1,
		Burger
	};

	enum TaillePizza
	{
		S = 1,
		M = 2,
		L = 4,
		XL = 8,
		XXL = 16
	};

	class Order : public ASerializable
	{
	private:
		enum ARecipe::TypeRecipe _recipeType;
		int _foodType;
		enum ARecipe::TaillePizza _size;
		std::list<enum AIngredient::TypeIngredient> _ingredientList;

	public:
		Order();
		~Order();

		std::string pack() const;
		void unpack(const std::string & data);

		bool isReady() const;
		void setRecipeType(enum ARecipe::TypeRecipe recipeType);
		void setFoodType(int foodType);
		void setSize(enum ARecipe::TaillePizza size);
		void addIngredient(enum AIngredient::TypeIngredient ingredient);

		enum ARecipe::TypeRecipe getRecipeType() const;
		int getFoodType() const;
		enum ARecipe::TaillePizza getSize() const;
		enum AIngredient::TypeIngredient getNextIngredient();

	private:
		void getIngredientsFromCSV(std::string & parsable_data);
	};

private:
	std::list<AIngredient::TypeIngredient> _requiredFood;
	enum ARecipe::TypeRecipe _recipeType;
	std::string _recipeName;
	int _foodType;
	enum ARecipe::TaillePizza _size;

public:
	virtual ~ARecipe();

	void addRequirement(AIngredient::TypeIngredient requirement);
	AIngredient::TypeIngredient getNextRequirement() const;
	virtual void addDecorator(AIngredient * decorator);

	enum ARecipe::TypeRecipe getRecipeType() const;
	int getFoodType() const;
	ARecipe::TaillePizza getSize() const;
	bool isReady() const;
	const std::string & getRecipeName() const;

	void setSize(ARecipe::TaillePizza size);

	ARecipe::Order * getOrder() const;

protected:
	ARecipe(enum ARecipe::TypeRecipe recipeType, int foodType, const std::string & recipeName, const std::string & name, double cookingTime, enum ARecipe::TaillePizza size);
};

std::ostream & operator<<(std::ostream & os, const ARecipe & recipe);

#endif /* !__ARECIPE_HH__ */