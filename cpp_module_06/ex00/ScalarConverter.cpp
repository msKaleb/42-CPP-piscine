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
	int			type = c.getType();

	switch (type)
	{
	case typeChar:
		std::cout << "is char" << std::endl;
		// explicit constructors here... after impossible check
		break;
	case typeInt:
		std::cout << "is int" << std::endl;
		break;
	case typeFloat:
		std::cout << "is float" << std::endl;
		break;
	case typeDouble:
		std::cout << "is double" << std::endl;
		break;
	default:
		std::cout << "is none" << std::endl;
		break;
	}
	// std::cout << c.getType() << std::endl;
}
