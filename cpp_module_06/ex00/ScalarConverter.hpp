#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "CheckType.hpp"
# include "types.h"

class	ScalarConverter
{

private:
	/* Orthodox canonical */
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	explicit ScalarConverter(int convertedLiteral);
	explicit ScalarConverter(double convertedLiteral);
	explicit ScalarConverter(float convertedLiteral);
	explicit ScalarConverter(char convertedLiteral);

public:
	static void	convert(std::string literal);
};

#endif /* SCALARCONVERTER_HPP */
