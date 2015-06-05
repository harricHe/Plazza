# Plazza

Plazza is an Epitech project that i made with Nicolas Lequain.The purpose of this project is to make you realize a simulation of a pizzeria, which is composed of the reception that accepts new commands, of several kitchens, themselves
with several cooks, themselves cooking several pizzas. It's written in C++ with the help of Ncurses.

## How to Use

If you launch the program without arguments, you will have this following message:

> Usage : ./plazza <time multiplier> <cooks per kitchen> <fridge refresh speed>

The time multiplier: a multiplier for the cooking time.

### Commands

After launch, you can command a pizza (or hamburger) by the following syntax

> TYPE SIZE NUMBER [;...]

> - TYPE =
> - SIZE = S|M|L|XL|XXL
> NUMBER = x[1..9][0..9]

#### example

> regina XXL x2; fantasia M x3; margarita S x1
