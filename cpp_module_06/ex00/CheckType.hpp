#ifndef CHECKTYPE_HPP
# define CHECKTYPE_HPP

# include <iostream>
# include <limits>
# include <cstdlib>
# include <cerrno>

# define MININT		std::numeric_limits<int>::min()
# define MAXINT		std::numeric_limits<int>::max()
# define MINFLOAT	std::numeric_limits<float>::min()
# define MAXFLOAT	std::numeric_limits<float>::max()
# define MINDOUBLE	std::numeric_limits<double>::min()
# define MAXDOUBLE	std::numeric_limits<double>::max()

class	CheckType
{
private:
	/* data */
	std::string	_literal;
public:
	/* Orthodox canonical */
	CheckType();
	~CheckType();
	CheckType(CheckType const &copy);
	CheckType &operator=(const CheckType &rhs);

	CheckType(std::string literal);

	bool	isInt() const;
	bool	isFloat() const;
	bool	isDouble() const;
	bool	isChar() const;
};

#endif /* CHECKTYPE_HPP */
