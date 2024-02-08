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
	int	len = this->_literal.length();
	int	plusMinus = 0;

	for (int i = 0; i < len; i++) {
		if (this->_literal[i] == '-' || this->_literal[i] == '+')
			plusMinus++;
	}
	if (plusMinus > 1)
		return false;
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
	int	points = 0, fNum = 0, plusMinus = 0;

	for (int i = 0; i < len; i++) {
		if (this->_literal[i] == 'f')
			fNum++;
		if (this->_literal[i] == '.')
			points++;
		else if (this->_literal[i] == '-' || this->_literal[i] == '+')
			plusMinus++;
	}
	if (points > 1 || fNum > 1 || plusMinus > 1)
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

bool	ScalarConverter::isDouble() const {
	std::string	doubleNumbers("-+1234567890.");

	int	len = this->_literal.length();
	int	points = 0, plusMinus = 0;

	for (int i = 0; i < len; i++) {
		if (this->_literal[i] == '.')
			points++;
		else if (this->_literal[i] == '-' || this->_literal[i] == '+')
			plusMinus++;
	}
	if (points != 1 || plusMinus > 1)
		return false;
	if (this->_literal.find_last_not_of(doubleNumbers) == std::string::npos) {
		long	number = std::atoll(this->_literal.c_str());
		if (errno != ERANGE && number > -std::numeric_limits<double>::max() \
			&& number < std::numeric_limits<double>::max()) { // how many decimals???
				double	tmp = std::atof(this->_literal.c_str());
				std::cout << static_cast<float>(tmp) << std::endl;
				return true;
			}
	}
	return false;
}

ScalarConverter::ScalarConverter(std::string const &literal):
	_literal(literal), _isInt(false), _isChar(false) {}

/* ---------------------------------- explicit constructors ---------------------------------- */
// int constructor
ScalarConverter::ScalarConverter(int input, std::string const &literal) : _literal(literal) {
	this->_floatType = static_cast<float>(input);
	this->_doubleType = static_cast<double>(input);
	this->_charType = static_cast<char>(input);

	std::cout << "char: ";
	if (isprint(this->_charType))
		std::cout << "'" << this->_charType << "'" << std::endl;
	else if (isascii(this->_charType))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (input > -std::numeric_limits<float>::max() \
		&& input < std::numeric_limits<float>::max())
		std::cout << std::setprecision(1) << std::fixed << static_cast<float>(input) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

// float constructor
ScalarConverter::ScalarConverter(float input, std::string const &literal) : _literal(literal) {
	this->_floatType = static_cast<float>(input);
}
/* ------------------------------------------------------------------------------------------- */

void	ScalarConverter::convert(std::string const &literal) {
	ScalarConverter	sC(literal);
	ScalarConverter	*ptr;

	// std::cout << "_literal: " << sC._literal << std::endl;
	if (sC.isInt())
		ptr = new ScalarConverter(std::atoi(literal.c_str()), literal);
		// std::cout << "is int" << std::endl;
	if (sC.isChar())
		std::cout << "is char" << std::endl;
	if (sC.isFloat())
		ptr = new ScalarConverter(static_cast<float>(std::atof(literal.c_str())), literal);
		// std::cout << "is float" << std::endl;
	if (sC.isDouble())
		std::cout << "is double" << std::endl;
	// delete ptr;


	// else
	// 	std::cout << "int: impossible" << std::endl;

	/* if (sC._isChar == true)
		std::cout << "char: " << sC._charType << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "float: " << sC._floatType << std::endl;
	std::cout << "double: " << sC._doubleType << std::endl; */
}
