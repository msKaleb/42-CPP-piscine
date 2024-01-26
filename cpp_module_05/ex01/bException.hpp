#ifndef BEXCEPTION_HPP
# define BEXCEPTION_HPP

# include <iostream>

class	bException : public std::exception
{
	virtual const char *what() const throw();
};

#endif /* BEXCEPTION_HPP */
