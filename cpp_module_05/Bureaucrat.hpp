#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class	Bureaucrat
{
private:
	/* data */
	std::string const	_name;
	unsigned int		_grade;

	Bureaucrat();

public:
	/* Orthodox canonical */
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, unsigned int grade);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	void	incGrade(void);
	void	decGrade(void);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* BUREAUCRAT_HPP */
