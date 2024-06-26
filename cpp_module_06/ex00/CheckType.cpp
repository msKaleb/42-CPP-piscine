#include "CheckType.hpp"

CheckType::CheckType() {
	// std::cout << "CheckType: Default Constructor Called" << std::endl;
}

CheckType::~CheckType() {
	// std::cout << "CheckType: Destructor Called" << std::endl;
}

CheckType::CheckType(CheckType const &copy) :
	_literal(copy.getLiteral()), _cNum(copy.getChar()), _iNum(copy.getInt()), _fNum(copy.getFloat()), _dNum(copy.getDouble()) {}

CheckType	&CheckType::operator=(const CheckType &rhs) {
	// std::cout << "CheckType: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->~CheckType();
		new(this) CheckType(rhs);
	}
	return *this;
}

CheckType::CheckType(std::string literal) : _literal(literal) { return ; }

/* ***************************************************************************************** */
bool	CheckType::isChar() const {
	if (this->_literal.length() > 1)
		return false;
	if (!isdigit(this->_literal[0]) && isascii(this->_literal[0]))
		return true;
	return false;
}

bool	CheckType::isInt() const {
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
		// int	number = std::atoi(this->_literal.c_str());
		long number = std::strtol(this->_literal.c_str(), NULL, 10);
		if (!errno && number < MAX_INT && number > MIN_INT)
			return true;
	}
	errno = 0;
	return false;
}

bool	CheckType::isFloat() const {
	// check first the pseudo literals
	std::string	pseudoLiterals[] = {"nanf", "-nanf", "inff", "-inff"};
	for (int i = 0; i < 4; i++)
		if (pseudoLiterals[i] == this->_literal)
			return true;

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

	std::string	floatNumbers("-+1234567890.f");
	if (this->_literal.find_last_not_of(floatNumbers) == std::string::npos) {
		// float	number = std::atof(this->_literal.c_str());
		float	number = std::strtof(this->_literal.c_str(), NULL);
		if (!errno && number > MIN_FLOAT && number < MAX_FLOAT)
			return true;
	}
	errno = 0;
	return false;
}

bool	CheckType::isDouble() const {
	// check first the pseudo literals
	std::string	pseudoLiterals[] = {"nan", "-nan", "inf", "-inf"};
	for (int i = 0; i < 4; i++)
		if (pseudoLiterals[i] == this->_literal)
			return true;

	int	points = 0, plusMinus = 0;
	for (size_t i = 0; i < this->_literal.length(); i++) {
		if (this->_literal[i] == '.')
			points++;
		else if (this->_literal[i] == '-' || this->_literal[i] == '+')
			plusMinus++;
	}
	if (points > 1 || plusMinus > 1)
		return false;

	std::string	doubleNumbers("-+1234567890.");
	if (this->_literal.find_last_not_of(doubleNumbers) == std::string::npos) {
		// double	number = std::atof(this->_literal.c_str());
		double	number = std::strtod(this->_literal.c_str(), NULL);
		// std::cout << (number > MIN_DOUBLE) << "|" << (number < MAX_DOUBLE) << std::endl;
		if (!errno && (number > MIN_DOUBLE && number < MAX_DOUBLE))
			return true;
	}
	errno = 0;
	return false;
}
/* ***************************************************************************************** */

/* ***************************************************************************************** */
char	CheckType::getChar() const { return this->_cNum; }
int		CheckType::getInt() const { return this->_iNum; }
float	CheckType::getFloat() const { return this->_fNum; }
double	CheckType::getDouble() const { return this->_dNum; }

std::string	CheckType::getLiteral() const { return this->_literal; }
/* ***************************************************************************************** */

/* ***************************************************************************************** */
void	CheckType::setChar(char cNum) { this->_cNum = cNum; }
void	CheckType::setInt(int iNum) { this->_iNum = iNum; }
void	CheckType::setFloat(float fNum) { this->_fNum = fNum; }
void	CheckType::setDouble(double dNum) { this->_dNum = dNum; }
/* ***************************************************************************************** */

int	CheckType::getType() {
	bool	(CheckType::*functPtr[])() const = {
		&CheckType::isChar,
		&CheckType::isInt,
		&CheckType::isFloat,
		&CheckType::isDouble
	};

	int	i;
	for (i = 0; i < 4; i++) {
		if ((this->*functPtr[i])())
			break ;
	}
	return i;
}
