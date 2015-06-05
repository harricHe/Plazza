/*
** Regina.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:38:11 2015 nlequain
** Last update Thu Apr 23 11:08:17 2015 nlequain
*/

#include "Regina.hpp"

Regina::Regina(enum ARecipe::TaillePizza size) : APizza(APizza::Regina, "regina", 2, size)
{
	this->addRequirement(AIngredient::Doe);
	this->addRequirement(AIngredient::Tomato);
	this->addRequirement(AIngredient::Gruyere);
	this->addRequirement(AIngredient::Ham);
	this->addRequirement(AIngredient::Mushroom);
}

Regina::~Regina()
{

}
