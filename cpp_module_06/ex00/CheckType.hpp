#ifndef CHECKTYPE_HPP
# define CHECKTYPE_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <string>

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

	bool	isInt() const;
	bool	isFloat() const;
	bool	isDouble() const;
	bool	isChar() const;
};

#endif /* CHECKTYPE_HPP */
