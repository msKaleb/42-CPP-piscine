#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	AForm;
class	ShrubberyCreationForm;
class	RobotomyRequestForm;
class	PresidentialPardonForm;

class	Intern
{
private:
	/* data */

public:
	/* Orthodox canonical */
	Intern();
	~Intern();
	Intern(Intern const &copy);
	Intern &operator=(const Intern &rhs);

	AForm	*makeForm(std::string const &formName, std::string const &formTarget);

	AForm	*shrubbery(std::string const &formTarget);
	AForm	*robotomy(std::string const &formTarget);
	AForm	*presidential(std::string const &formTarget);
};

#endif /* INTERN_HPP */
