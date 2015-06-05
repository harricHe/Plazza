/*
** Parser.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sat Apr 25 09:55:09 2015 nlequain
** Last update Sun Apr 26 22:14:55 2015 nlequain
*/

#include <algorithm>
#include <map>
#include <sstream>
#include "Parser.hpp"

/*
** Parser
*/

Parser::Parser()
{

}

Parser::~Parser()
{

}

std::list<Parser::Order> * Parser::parseOrder(const std::string & orderString)
{
	std::list<Parser::Order> * orderList = new std::list<Parser::Order>;
	std::string parsableOrderString = orderString;
	std::size_t pos = 0;

	this->_errors.clear();
	this->_errors.str("");
	while (pos != std::string::npos)
	{
		pos = parsableOrderString.find(";");
		this->parseSingleOrder(orderList, parsableOrderString.substr(0, pos));
		parsableOrderString.erase(0, pos + 1);
	}
	this->_errorString = this->_errors.str();
	return orderList;
}

void Parser::parseSingleOrder(std::list<Parser::Order> * orderList, const std::string & orderString)
{
	std::vector<std::string> orderParameters;
	std::string parsableOrderString = orderString;
	std::size_t pos = 0;

	while (pos != std::string::npos)
	{
		pos = parsableOrderString.find(" ");
		orderParameters.push_back(parsableOrderString.substr(0, pos));
		parsableOrderString.erase(0, pos + 1);
	}
	if (orderParameters.size() == 3)
		this->createSimpleOrder(orderList, orderParameters);
	else if (orderParameters.size() > 3)
		this->createComplexOrder(orderList, orderParameters);
	else
		this->_errors << "Invalid order : " << "\"" << orderString << "\"" << ". ";
}

void Parser::createSimpleOrder(std::list<Parser::Order> * orderList, const std::vector<std::string> & orderParameters)
{
	Parser::Order order;

	order.setRecipeType("pizza");
	order.setFoodType(orderParameters.at(0));
	if (order.setSize(orderParameters.at(1)) == false)
	{
		this->_errors << "Unknown size : " << "\"" << orderParameters.at(1) << "\"" << ". ";
		return ;
	}
	this->insertOrder(orderList, order, orderParameters.at(2));
}

void Parser::createComplexOrder(std::list<Parser::Order> * orderList, const std::vector<std::string> & orderParameters)
{
	Parser::Order order;

	order.setRecipeType(orderParameters.at(0));
	order.setFoodType(orderParameters.at(1));
	if (order.setSize(orderParameters.at(2)) == false)
	{
		this->_errors << "Unknown size : " << "\"" << orderParameters.at(2) << "\"" << ". ";
		return ;
	}
	for (std::size_t i = 4; i < orderParameters.size(); ++i)
		order.addAdditionalIngredient(orderParameters.at(i));
	this->insertOrder(orderList, order, orderParameters.at(3));
}

void Parser::insertOrder(std::list<Parser::Order> * orderList, const Parser::Order & order, const std::string & amountParameter)
{
	std::stringstream amountConvertor;
	std::size_t amount;

	if (amountParameter.length() < 2 or amountParameter.at(0) != 'x')
	{
		this->_errors << "Syntax error (wrong number) : " << "\"" << amountParameter << "\"" << ". ";
		return ;
	}
	amountConvertor.str(amountParameter.substr(1, std::string::npos));
	if (not (amountConvertor >> amount))
	{
		this->_errors << "Syntax error (wrong number) : " << "\"" << amountParameter << "\"" << ". ";
		return ;
	}
	for (std::size_t i = 0; i < amount; ++i)
		orderList->push_back(order);
}

const std::string & Parser::getError()
{
	return this->_errorString;
}

/*
** Order
*/

Parser::Order::Order()
{

}

Parser::Order::~Order()
{

}

void Parser::Order::setRecipeType(const std::string & recipeType)
{
	this->_recipeType = recipeType;
}

void Parser::Order::setFoodType(const std::string & foodType)
{
	this->_foodType = foodType;
}

void Parser::Order::setSize(ARecipe::TaillePizza size)
{
	this->_size = size;
}

bool Parser::Order::setSize(const std::string & size)
{
	std::map<std::string, ARecipe::TaillePizza> sizeConvertor;
	std::string sizeUpper = size;

	sizeConvertor["S"] = ARecipe::S;
	sizeConvertor["M"] = ARecipe::M;
	sizeConvertor["L"] = ARecipe::L;
	sizeConvertor["XL"] = ARecipe::XL;
	sizeConvertor["XXL"] = ARecipe::XXL;
	std::transform(sizeUpper.begin(), sizeUpper.end(), sizeUpper.begin(), ::toupper);
	if (sizeConvertor.find(sizeUpper) == sizeConvertor.end())
		return false;
	this->setSize(sizeConvertor[sizeUpper]);
	return true;
}

void Parser::Order::addAdditionalIngredient(const std::string & ingredient)
{
	this->_additionalIngredients.push_back(ingredient);
}

const std::string & Parser::Order::getRecipeType() const
{
	return this->_recipeType;
}

const std::string & Parser::Order::getFoodType() const
{
	return this->_foodType;
}

ARecipe::TaillePizza Parser::Order::getSize() const
{
	return this->_size;
}

std::string Parser::Order::getNextAdditionalIngredient()
{
	std::string ingredient = this->_additionalIngredients.front();
	this->_additionalIngredients.pop_front();
	return ingredient;
}

bool Parser::Order::isReady() const
{
	return this->_additionalIngredients.empty();
}

