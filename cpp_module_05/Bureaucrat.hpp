#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
private:
	/* data */

public:
	/* Orthodox canonical */
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);

};

#endif /* BUREAUCRAT_HPP */
