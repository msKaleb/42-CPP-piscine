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

	Bureaucrat();

public:
	class	bException : public std::exception
	{
		virtual const char *what() const throw();
		// virtual const char* bException::what() const;
	};

	/* Orthodox canonical */
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, unsigned int grade);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	bException	GradeTooHighException(void);
	bException	GradeTooLowException(void);

	void	incGrade(void);
	void	decGrade(void);

	void	signForm(Form &f) const;
};


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* BUREAUCRAT_HPP */
