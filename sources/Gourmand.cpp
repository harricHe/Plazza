/*
** Gourmand.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 22:41:05 2015 nlequain
** Last update Sun Apr 26 22:43:09 2015 nlequain
*/

#include "Gourmand.hpp"

Gourmand::Gourmand(enum ARecipe::TaillePizza size) : ABurger(ABurger::Gourmand, "gourmand", 3, size)
{
	this->addRequirement(AIngredient::Doe);
	this->addRequirement(AIngredient::Tomato);
	this->addRequirement(AIngredient::Gruyere);
	this->addRequirement(AIngredient::Eggplant);
	this->addRequirement(AIngredient::GoatCheese);
}

Gourmand::~Gourmand()
{

}
