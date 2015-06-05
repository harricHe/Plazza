/*
** Parser.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 09:38:25 2015 nlequain
** Last update Sun Apr 26 22:14:35 2015 nlequain
*/

#ifndef __PARSER_HH__
# define __PARSER_HH__

# include <string>
# include <vector>
# include <list>
# include <sstream>
# include "ARecipe.hpp"

class Parser
{
public:
	class Order
	{
	private:
		std::string _recipeType;
		std::string _foodType;
		ARecipe::TaillePizza _size;
		std::list<std::string> _additionalIngredients;

	public:
		Order();
		~Order();
		void setRecipeType(const std::string & recipeType);
		void setFoodType(const std::string & foodType);
		void setSize(ARecipe::TaillePizza size);
		bool setSize(const std::string & size);
		void addAdditionalIngredient(const std::string & ingredient);
		const std::string & getRecipeType() const;
		const std::string & getFoodType() const;
		ARecipe::TaillePizza getSize() const;
		std::string getNextAdditionalIngredient();
		bool isReady() const;
	};

private: /* temporary data */
	std::stringstream _errors;
	std::string _errorString;

public:
	Parser();
	~Parser();
	std::list<Parser::Order> * parseOrder(const std::string & orderString);
	const std::string & getError();

private:
	void parseSingleOrder(std::list<Parser::Order> * orderList, const std::string & orderString);
	void createSimpleOrder(std::list<Parser::Order> * orderList, const std::vector<std::string> & orderParameters);
	void createComplexOrder(std::list<Parser::Order> * orderList, const std::vector<std::string> & orderParameters);
	void insertOrder(std::list<Parser::Order> * orderList, const Parser::Order & order, const std::string & amountParameter);
};

#endif /* !__PARSER_HH__ */