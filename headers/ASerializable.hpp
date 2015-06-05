/*
** ASerializable.hpp for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza/headers
**
** Made by nlequain
** Login   <nlequain@epitech.net>
**
** Started on  Mon Apr 20 18:11:12 2015 nlequain
** Last update Sun Apr 26 20:52:39 2015 nlequain
*/

#ifndef __ASERIALIZABLE_HH__
# define __ASERIALIZABLE_HH__

# include <sstream>
# include <string>

# define SERIALIZER_CATEGORY_SEPARATOR ";"
# define SERIALIZER_SUBCATEGORY_SEPARATOR ","

class ASerializable
{
public:
	enum DataType
	{
		NoType = 1,
		Recipe,
		Fridge,
		Cook,
		KitchenClosing
	};

public:
	virtual ~ASerializable() {}
	virtual std::string pack() const = 0;
	virtual void unpack(const std::string & data) = 0;
	static void writeType(std::stringstream & serializedOrder, ASerializable::DataType dataType);
	static ASerializable::DataType getType(std::string & data);

protected:
	template <typename T>
	static void getValue(std::string & parsable_data, T & value_to_change)
	{
		std::stringstream dataConverter;
		std::size_t pos;
		int valueIntConverter;

		pos = parsable_data.find(SERIALIZER_CATEGORY_SEPARATOR);
		if (pos == std::string::npos)
			return;

		dataConverter.str(parsable_data.substr(0, pos));
		dataConverter >> valueIntConverter;
		value_to_change = static_cast<T>(valueIntConverter);

		parsable_data.erase(0, pos + 1);
	}

};

#endif /* !__ASERIALIZABLE_HH__ */