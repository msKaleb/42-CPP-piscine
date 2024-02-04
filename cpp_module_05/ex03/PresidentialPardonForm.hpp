#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	/* data */

	PresidentialPardonForm();
public:
	/* Orthodox canonical */
	PresidentialPardonForm(std::string const target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	virtual void	executeDerived() const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
