#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm
{
private:
	/* data */

public:
	/* Orthodox canonical */
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
