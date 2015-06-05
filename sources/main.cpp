/*
** main.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Thu Apr 16 23:15:07 2015 nlequain
** Last update Sun Apr 26 23:36:48 2015 nlequain
*/

#include <iostream>
#include "NCursesIOManager.hpp"
#include "AForkable.hpp"
#include "ANamedPipe.hpp"
#include "AThreadable.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage : ./plazza <time multiplier> <cooks per kitchen> <fridge refresh speed>" << std::endl;
		return 1;
	}
	NCursesIOManager iomanager(av[1], av[2], av[3]);
	iomanager.init();
	try
	{
		iomanager.run();
	}
	catch (AForkable::ForkException & exception) {
		iomanager.destroy();
		std::cout << "An error occurred : " << exception.what() << std::endl;
		return 1;
	}
	catch (ANamedPipe::NamedPipeException & exception) {
		iomanager.destroy();
		std::cout << "An error occurred : " << exception.what() << std::endl;
		return 1;
	}
	catch (AThreadable::ThreadException & exception) {
		iomanager.destroy();
		std::cout << "An error occurred : " << exception.what() << std::endl;
		return 1;
	}
	catch (NCursesIOManager::NCursesException & exception) {
		iomanager.destroy();
		std::cout << "An error occurred : " << exception.what() << std::endl;
		return 1;
	}
	iomanager.destroy();
	return 0;
}
