#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	/* data */
	std::string const	_name;
	bool				_signed;
	unsigned int const	_signGrade;
	unsigned int const	_execGrade;

	std::string const	_target;
	bool				_executed;

	AForm();

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
	class	FormNotSigned : public std::exception {
		virtual const char *what() const throw();
	};

	/* Orthodox canonical */
	virtual ~AForm();
	AForm(AForm const &copy);
	AForm &operator=(const AForm &rhs);

	AForm(std::string name, unsigned int toSign, unsigned int toExecute);

	// getters
	std::string const	getName(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getSignExec(void) const;
	bool				getSigned(void) const;
	std::string const	getTarget(void) const;
	bool				getExecuted(void) const;

	// setters
	void	setTarget(std::string const &target);

	virtual void	execute(Bureaucrat const &executor) const;
	// virtual void	executeDerived(Bureaucrat const &executor) const = 0; // pure virtual, to be implemented
	void			beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &o, AForm const &i);

#endif /* AFORM_HPP */
