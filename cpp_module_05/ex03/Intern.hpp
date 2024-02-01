#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class	AForm;

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
};

#endif /* INTERN_HPP */
