#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"
# include "bException.hpp"

class	Bureaucrat;

class	Form
{
private:
	/* data */
	std::string const	_name;
	bool				_signed;
	unsigned int		_signGrade;
	unsigned int		_execGrade;

	Form();

public:
	/* Orthodox canonical */
	~Form();
	Form(Form const &copy);
	Form &operator=(const Form &rhs);

	Form(std::string name, unsigned int toSign, unsigned int toExecute);

	// exceptions
	bException	GradeTooHighException(void);
	bException	GradeTooLowException(void);

	// getters
	std::string		getName(void) const;
	bool			getSigned(void) const;
	unsigned int	getSignGrade(void) const;
	unsigned int	getSignExec(void) const;

	void	beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &o, Form const &i);

#endif /* FORM_HPP */
