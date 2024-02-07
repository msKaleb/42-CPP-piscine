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

bool	ScalarConverter::isInt() const {
	std::string	numbers("-+1234567890");

	if (this->_literal.find_last_not_of(numbers) == std::string::npos) {
		long	number = std::atoll(this->_literal.c_str());
		if (number < INT_MAX && number > INT_MIN)
			return true;
	}
	return false;
}

bool	ScalarConverter::isChar() const {
	if (this->_literal.length() > 1)
		return false;
	int	len = this->_literal.length();
	for (int i = 0; i < len; i++) {
		if ((this->_literal[i] >= 'a' && this->_literal[i] <= 'z') \
			|| (this->_literal[i] >= 'A' && this->_literal[i] <= 'Z'))
			return true;
	}
	return false;
}

bool	ScalarConverter::isFloat() const {
	std::string	floatNumbers("-+1234567890.f");

	int	len = this->_literal.length();
	int	points = 0, fNum = 0;

	for (int i = 0; i < len; i++) {
		if (this->_literal[i] == 'f')
			fNum++;
		if (this->_literal[i] == '.')
			points++;
	}
	if (points > 1 || fNum > 1)
		return false;
	if ((points == 0 && fNum > 0) || this->_literal[len - 1] != 'f')
		return false;
	if (this->_literal.find_last_not_of(floatNumbers) == std::string::npos) {
		long	number = std::atoll(this->_literal.c_str());
		if (errno != ERANGE && number > -std::numeric_limits<float>::max() \
			&& number < std::numeric_limits<float>::max()) // how many decimals???
			return true;
	}
	return false;
}

ScalarConverter::ScalarConverter(std::string const &literal):
	_literal(literal), _isInt(false), _isChar(false) {}

void	ScalarConverter::printInt(int number) const { // bad
	if (number < INT_MAX && number > INT_MIN)
		std::cout << "int: " << static_cast<int>(number) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	ScalarConverter::printChar(std::string const &literal) const {

}

void	ScalarConverter::convert(std::string const &literal) {
	ScalarConverter	sC(literal);

	std::cout << "_literal: " << sC._literal << std::endl;
	if (sC.isInt())
		std::cout << "is int" << std::endl;
	if (sC.isChar())
		std::cout << "is char" << std::endl;
	if (sC.isFloat())
		std::cout << "is float" << std::endl;
	// else
	// 	std::cout << "int: impossible" << std::endl;

	/* if (sC._isChar == true)
		std::cout << "char: " << sC._charType << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "float: " << sC._floatType << std::endl;
	std::cout << "double: " << sC._doubleType << std::endl; */
}
