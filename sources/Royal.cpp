/*
** Royal.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 22:39:14 2015 nlequain
** Last update Sun Apr 26 22:43:08 2015 nlequain
*/

#include "Royal.hpp"

Royal::Royal(enum ARecipe::TaillePizza size) : ABurger(ABurger::Royal, "royal", 4, size)
{
	this->addRequirement(AIngredient::Doe);
	this->addRequirement(AIngredient::Tomato);
	this->addRequirement(AIngredient::Gruyere);
}

Royal::~Royal()
{

}
