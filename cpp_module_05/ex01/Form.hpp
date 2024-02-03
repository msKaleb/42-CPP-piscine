#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	/* data */
	std::string const	_name;
	bool				_signed;
	unsigned int const	_signGrade;
	unsigned int const	_execGrade;

	Form();

public:
	/* exception classes */
	class	GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

	class	FormAlreadySigned : public std::exception {
		virtual const char *what() const throw();
	};

	/* Orthodox canonical */
	~Form();
	Form(Form const &copy);
	Form &operator=(const Form &rhs);

	Form(std::string name, unsigned int toSign, unsigned int toExecute);

	// getters
	std::string const	getName(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getSignExec(void) const;
	bool				getSigned(void) const;

	void	beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &o, Form const &i);

#endif /* FORM_HPP */
