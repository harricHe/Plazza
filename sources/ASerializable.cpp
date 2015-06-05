/*
** ASerializable.cpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/sources
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Sun Apr 26 15:32:43 2015 nlequain
** Last update Sun Apr 26 20:43:05 2015 nlequain
*/

#include "ASerializable.hpp"

void ASerializable::writeType(std::stringstream & serializedOrder, ASerializable::DataType dataType)
{
	serializedOrder << dataType;
	serializedOrder << SERIALIZER_CATEGORY_SEPARATOR;
}

ASerializable::DataType ASerializable::getType(std::string & data)
{
	ASerializable::DataType type;

	ASerializable::getValue<ASerializable::DataType>(data, type);
	return type;
}
