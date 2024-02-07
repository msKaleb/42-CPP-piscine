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
	std::string	numbers("1234567890");

	if (this->_literal.find_last_not_of(numbers) == std::string::npos)
		return true;
	return false;
}

bool	ScalarConverter::isChar() const {
	std::string	characters("1234567890"); // bad

	if (this->_literal.find_first_of(characters) == std::string::npos) {
		return true;
	}
	return false;
}

ScalarConverter::ScalarConverter(std::string const &literal):
	_literal(literal), _isInt(false), _isChar(false) {
	/* this->_intType = static_cast<int>(std::atoi(_literal.c_str()));
	this->_floatType = static_cast<float>(std::atof(_literal.c_str()));
	this->_doubleType = static_cast<double>(std::atof(_literal.c_str()));
	this->_charType = static_cast<char>(std::atoi(_literal.c_str()));

	if (_doubleType > __INT_MAX__)
		this->_isInt = false;
	if (_doubleType > 255)
		this->_isChar = false; */
}

void	ScalarConverter::convert(std::string const &literal) {
	ScalarConverter	sC(literal);
	long		tmp;

	std::cout << "_literal: " << sC._literal << std::endl;
	// if (sC.isInt()) {
		tmp = std::atoll(sC._literal.c_str());
		std::cout << "tmp: " << tmp << std::endl;
		if (tmp < INT_MAX && tmp > INT_MIN) {
			sC._intType = tmp;
			std::cout << "int: " << sC._intType << std::endl;
		}
		else
			std::cout << "int: impossible" << std::endl;
	// }
	// else
	// 	std::cout << "int: impossible" << std::endl;

	/* if (sC._isChar == true)
		std::cout << "char: " << sC._charType << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "float: " << sC._floatType << std::endl;
	std::cout << "double: " << sC._doubleType << std::endl; */
}
