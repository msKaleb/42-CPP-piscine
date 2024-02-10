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
ScalarConverter::ScalarConverter(int convertedLiteral) {
	// print char value ------------------------
	if (!isprint(convertedLiteral) && !isascii(convertedLiteral))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(convertedLiteral))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << convertedLiteral << "'" << std::endl;

	// print int value ------------------------
	std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// print double value ------------------------
	std::cout << "double: " << static_cast<double>(convertedLiteral) << std::endl;

	// print float value ------------------------
	std::cout << "float: " << static_cast<float>(convertedLiteral) << "f" << std::endl;
}

/* ***************************************************************************************** */
ScalarConverter::ScalarConverter(double convertedLiteral) {
	// print char value ------------------------
	if (!isprint(convertedLiteral) && !isascii(convertedLiteral))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(convertedLiteral))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(convertedLiteral) << "'" << std::endl;

	// print int value ------------------------
	if (convertedLiteral < MIN_INT || convertedLiteral > MAX_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// print double value ------------------------
	std::cout << "double: " << convertedLiteral << std::endl;

	// print float value ------------------------
	if (convertedLiteral < MIN_FLOAT || convertedLiteral > MAX_FLOAT)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(convertedLiteral) << "f" << std::endl;
}

/* ***************************************************************************************** */

/* ***************************************************************************************** */

/* ***************************************************************************************** */
void	ScalarConverter::convert(std::string literal) {
	ScalarConverter conversion;

	CheckType	c(literal);
	int			type = c.getType();
	// int			iLit;

	switch (type)
	{
	case typeChar:
		std::cout << "is char" << std::endl;
		c.setChar(literal[0]);
		// explicit constructors here... after impossible check
		break;
	case typeInt:
		// std::cout << "is int" << std::endl;
		c.setInt(atoi(literal.c_str()));
		// conversion = c.getInt(); // not OK, explicit constructor
		conversion = ScalarConverter(c.getInt());
		break;
	case typeFloat:
		std::cout << "is float" << std::endl;
		break;
	case typeDouble:
		// std::cout << "is double" << std::endl;
		c.setDouble(atof(literal.c_str()));
		// conversion = c.getDouble(); // not OK, explicit constructor
		conversion = ScalarConverter(c.getDouble());
		break;
	default:
		std::cout << "is none" << std::endl;
		break;
	}
	// std::cout << c.getType() << std::endl;
}
