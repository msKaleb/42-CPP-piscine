#include "ScalarConverter.hpp"
#include "colors.h"

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
ScalarConverter::ScalarConverter(char convertedLiteral) {
	std::cout << std::fixed << std::setprecision(1);
	// print char value ------------------------
	std::cout << "char: '" << convertedLiteral << "'" << std::endl;

	// print int value ------------------------
	std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// print float value ------------------------
	std::cout << "float: " << static_cast<float>(convertedLiteral) << "f" << std::endl;

	// print double value ------------------------
	std::cout << "double: " << static_cast<double>(convertedLiteral) << std::endl;
}

/* ***************************************************************************************** */
ScalarConverter::ScalarConverter(int convertedLiteral) {
	std::cout << std::fixed << std::setprecision(1);
	// print char value ------------------------
	if (!isascii(convertedLiteral))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(convertedLiteral))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(convertedLiteral) << "'" << std::endl;

	// print int value ------------------------
	std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// print float value ------------------------
	std::cout << "float: " << static_cast<float>(convertedLiteral) << "f" << std::endl;

	// print double value ------------------------
	std::cout << "double: " << static_cast<double>(convertedLiteral) << std::endl;
}

/* ***************************************************************************************** */
ScalarConverter::ScalarConverter(float convertedLiteral) {
	// std::cout << std::setprecision(2) << std::fixed;
	// print char value ------------------------
	if (!isascii(convertedLiteral))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(convertedLiteral))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(convertedLiteral) << "'" << std::endl;

	// print int value ------------------------
	if ((convertedLiteral < MIN_INT || convertedLiteral > MAX_INT)
		|| isnanf(convertedLiteral) || isinff(convertedLiteral))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// get the suffix for floating point numbers
	std::stringstream	ss;
	ss << convertedLiteral;
	std::string	strNum(ss.str());
	std::string	suffix = "";
	if (strNum.find('.') == std::string::npos)
		suffix = ".0";

	// print float value ------------------------
	std::cout << "float: " << convertedLiteral << suffix << "f" << std::endl;

	// print double value ------------------------
	std::cout << "double: " << static_cast<double>(convertedLiteral) << suffix << std::endl;
}

/* ***************************************************************************************** */
ScalarConverter::ScalarConverter(double convertedLiteral) {
	// print char value ------------------------
	if (!isascii(convertedLiteral))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(convertedLiteral))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(convertedLiteral) << "'" << std::endl;

	// print int value ------------------------
	if (convertedLiteral < MIN_INT || convertedLiteral > MAX_INT
		|| isnan(convertedLiteral) || isinf(convertedLiteral))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(convertedLiteral) << std::endl;

	// get the suffix for floating point numbers
	std::stringstream	ss;
	ss << convertedLiteral;
	std::string	strNum(ss.str());
	std::string	suffix = "";
	if (strNum.find('.') == std::string::npos)
		suffix = ".0";

	// print float value ------------------------
	if ((convertedLiteral < MIN_FLOAT || convertedLiteral > MAX_FLOAT)
		&& (!isnan(convertedLiteral) && !isinf(convertedLiteral)))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(convertedLiteral) << suffix << "f" << std::endl;

	// print double value ------------------------
	std::cout << "double: " << convertedLiteral << suffix << std::endl;
}

/* ***************************************************************************************** */
void	ScalarConverter::convert(std::string literal) {
	ScalarConverter conversion;

	CheckType	c(literal);
	int			type = c.getType();

	switch (type)
	{
	case typeChar:
		std::cout << YELLOW << "is char" << RESET << std::endl;
		c.setChar(literal[0]);
		conversion = ScalarConverter(c.getChar());
		break;
	case typeInt:
		std::cout << YELLOW << "is int" << RESET << std::endl;
		c.setInt(atoi(literal.c_str()));
		// conversion = c.getInt(); // not OK, explicit constructor
		conversion = ScalarConverter(c.getInt());
		break;
	case typeFloat:
		std::cout << YELLOW << "is float" << RESET << std::endl;
		c.setFloat(atof(literal.c_str()));
		conversion = ScalarConverter(c.getFloat());
		break;
	case typeDouble:
		std::cout << YELLOW << "is double" << RESET << std::endl;
		c.setDouble(atof(literal.c_str()));
		// conversion = c.getDouble(); // not OK, explicit constructor
		conversion = ScalarConverter(c.getDouble());
		break;
	default:
		std::cout << RED << "is none" << RESET << std::endl;
		break;
	}
	// std::cout << c.getType() << std::endl;
}
