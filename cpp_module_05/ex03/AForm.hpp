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
		public: virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public: virtual const char *what() const throw();
	};
	class	FormAlreadySigned : public std::exception {
		public: virtual const char *what() const throw();
	};
	class	FormNotSigned : public std::exception {
		public: virtual const char *what() const throw();
	};

	/* Orthodox canonical */
	virtual ~AForm();
	AForm(AForm const &copy);
	AForm &operator=(const AForm &rhs);

	AForm(std::string name, unsigned int toSign, unsigned int toExecute, std::string const target);

	// getters
	std::string const	getName(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getSignExec(void) const;
	bool				getSigned(void) const;
	std::string const	getTarget(void) const;
	bool				getExecuted(void) const;

	// setters
	void	setExecuted(bool status);

	void	execute(Bureaucrat const &executor) const;
	void	beSigned(Bureaucrat &b);

	virtual void	executeDerived() const = 0; // pure virtual, to be implemented
};

std::ostream	&operator<<(std::ostream &o, AForm const &i);

#endif /* AFORM_HPP */
