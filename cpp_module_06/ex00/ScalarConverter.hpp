#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>

class	ScalarConverter
{
private:
	/* Orthodox canonical */
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	ScalarConverter(std::string const &literal);
	/* data */
	std::string const	_literal;

	int		_intType;
	float	_floatType;
	double	_doubleType;
	char	_charType;

	bool	_isInt;
	bool	_isChar;

public:

	static void	convert(std::string const &literal);

};

#endif /* SCALARCONVERTER_HPP */
