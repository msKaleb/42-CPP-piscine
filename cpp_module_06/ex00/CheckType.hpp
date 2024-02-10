#ifndef CHECKTYPE_HPP
# define CHECKTYPE_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <string>
# include "ScalarConverter.hpp"

# define MIN_INT	std::numeric_limits<int>::min()
# define MAX_INT	std::numeric_limits<int>::max()
# define MIN_FLOAT	std::numeric_limits<float>::min()
# define MAX_FLOAT	std::numeric_limits<float>::max()
# define MIN_DOUBLE	std::numeric_limits<double>::min()
# define MAX_DOUBLE	std::numeric_limits<double>::max()

class	CheckType
{
private:
	/* data */
	std::string	_literal;
	char		_cNum;
	int			_iNum;
	float		_fNum;
	double		_dNum;

public:
	/* Orthodox canonical */
	CheckType();
	~CheckType();
	CheckType(CheckType const &copy);
	CheckType &operator=(const CheckType &rhs);

	CheckType(std::string literal);
	// explicit constructors here...

	int	getType();

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	void	setChar(char cNum);
	void	setInt(int iNum);
	void	setFloat(float fNum);
	void	setDouble(double dNum);

	void	printFromChar(char cNum);
	void	printFromInt(int iNum);
	void	printFromFloat(float fNum);
	void	printFromDouble(double dNum);

	bool	isInt() const;
	bool	isFloat() const;
	bool	isDouble() const;
	bool	isChar() const;
};

#endif /* CHECKTYPE_HPP */
