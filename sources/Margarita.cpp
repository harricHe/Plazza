/*
** Margarita.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Fri Apr 17 21:38:11 2015 nlequain
** Last update Thu Apr 23 11:09:23 2015 nlequain
*/

#include "Margarita.hpp"

Margarita::Margarita(enum ARecipe::TaillePizza size) : APizza(APizza::Margarita, "margarita", 1, size)
{
	this->addRequirement(AIngredient::Doe);
	this->addRequirement(AIngredient::Tomato);
	this->addRequirement(AIngredient::Gruyere);
}

Margarita::~Margarita()
{

}
