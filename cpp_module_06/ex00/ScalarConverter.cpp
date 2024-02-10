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

ScalarConverter::ScalarConverter(int iLit) {
	// std::cout << "errno: " << errno << std::endl;
	std::cout << "int: " << iLit << std::endl;
}

/* ***************************************************************************************** */
void	ScalarConverter::convert(std::string literal) {
	ScalarConverter conversion;

	CheckType	c(literal);
	int			type = c.getType();
	int			iLit;

	switch (type)
	{
	case typeChar:
		std::cout << "is char" << std::endl;
		c.setChar(literal[0]);
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
		c.setDouble(atof(literal.c_str()));

		// put all the casts into a function (c.fromDouble())
		if (c.getDouble() < MININT || c.getDouble() > MAXINT)
			std::cout << "int: impossible" << std::endl;
		else
			conversion = ScalarConverter(static_cast<int>(c.getDouble()));
			// conversion = c.getDouble(); // not OK, explicit constructor
		break;
	default:
		std::cout << "is none" << std::endl;
		break;
	}
	// std::cout << c.getType() << std::endl;
}
