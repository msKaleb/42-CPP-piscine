#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
private:
	/* data */
	std::string const	_name;
	unsigned int		_grade;

	/* private constructor */
	Bureaucrat();

public:
	/* exception classes */
	class	GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, unsigned int grade);

	std::string const	getName(void) const;
	unsigned int		getGrade(void) const;

	void	incGrade(void);
	void	decGrade(void);

	void	signForm(Form &f);
};


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* BUREAUCRAT_HPP */
