#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	// std::cout << "ScalarConverter: Default Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	// std::cout << "ScalarConverter: Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
	// std::cout << "ScalarConverter: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs) {
	// std::cout << "ScalarConverter: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

/* ***************************************************************************************** */
void	ScalarConverter::convert(std::string literal) {
	CheckType	c(literal);

	if (c.isInt())
		std::cout << "is int" << std::endl;
	else if (c.isDouble())
		std::cout << "is double" << std::endl;
}
