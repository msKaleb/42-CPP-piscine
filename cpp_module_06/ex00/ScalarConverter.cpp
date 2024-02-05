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

ScalarConverter::ScalarConverter(std::string const &literal):
	_literal(literal), _isInt(true), _isChar(true) {
	this->_intType = static_cast<int>(std::atoi(_literal.c_str()));
	this->_floatType = static_cast<float>(std::atof(_literal.c_str()));
	this->_doubleType = static_cast<double>(std::atof(_literal.c_str()));
	this->_charType = static_cast<char>(std::atoi(_literal.c_str()));

	if (_doubleType > __INT_MAX__)
		this->_isInt = false;
	if (_doubleType > 255)
		this->_isChar = false;
}

void	ScalarConverter::convert(std::string const &literal) {
	ScalarConverter	sC(literal);

	std::cout << "_literal: " << sC._literal << std::endl;
	if (sC._isChar == true)
		std::cout << "char: " << sC._charType << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (sC._isInt)
		std::cout << "int: " << sC._intType << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << sC._floatType << std::endl;
	std::cout << "double: " << sC._doubleType << std::endl;
}
