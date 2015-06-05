/*
** Fantasia.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:38:11 2015 nlequain
** Last update Sun Apr 26 22:41:42 2015 nlequain
*/

#include "Fantasia.hpp"

Fantasia::Fantasia(enum ARecipe::TaillePizza size) : APizza(APizza::Fantasia, "fantasia", 4, size)
{
	this->addRequirement(AIngredient::Doe);
	this->addRequirement(AIngredient::Tomato);
	this->addRequirement(AIngredient::Eggplant);
	this->addRequirement(AIngredient::GoatCheese);
}

Fantasia::~Fantasia()
{

}
