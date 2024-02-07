#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits.h>

class	ScalarConverter
{
private:
	/* Orthodox canonical */
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	explicit ScalarConverter(std::string const &literal);
	/* data */
	std::string const	_literal;

	int		_intType;
	float	_floatType;
	double	_doubleType;
	char	_charType;

	bool	_isInt;
	bool	_isChar;

public:
	bool	isInt() const;
	bool	isFloat() const;
	bool	isDouble() const;
	bool	isChar() const;

	static void	convert(std::string const &literal);

};

#endif /* SCALARCONVERTER_HPP */
