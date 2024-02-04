#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */
# define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"		/* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"		/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */

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
		public: virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public: virtual const char *what() const throw();
	};

	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, unsigned int grade);

	std::string const	getName(void) const;
	unsigned int		getGrade(void) const;

	void	incGrade(void);
	void	decGrade(void);
};


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* BUREAUCRAT_HPP */
