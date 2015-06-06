# Plazza

Plazza is an Epitech project that i made with Nicolas Lequain.The purpose of this project is to make  a simulation of a pizzeria, which is composed of the reception that accepts new commands, of several kitchens, themselves
with several cooks, themselves cooking several pizzas. It's written in C++ with the help of Ncurses.

## How to Use

The program take three arguments:

- The time multiplier: a multiplier for the cooking time.
- cooks by kitchen
- fridge refresh speed

### Commands

After launch, you can command a pizza (or hamburger) by the following syntax

### Simple command

> TYPE SIZE NUMBER [;...]

- TYPE = regina|margarita|americaine|fantasia
- SIZE = S|M|L|XL|XXL
- NUMBER = x[1..9][0..9]

#### example

> regina XXL x2; fantasia M x3; margarita S x1

### Complete command

> RECIPE TYPE SIZE NUMBER [INGREDIENT] [;...]

- RECIPE = pizza|burger
- SIZE = S|M|L|XL|XXL
- NUMBER = x[1..9][0..9]
- INGREDIENT = ham|gruyere|doe|tomato|steak|mushroom|goatcheese|eggplant