#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <ctime>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private:
	/* data */
	RobotomyRequestForm();

public:
	/* Orthodox canonical */
	RobotomyRequestForm(std::string const target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	// virtual void	execute(Bureaucrat const &executor) const;
	virtual void	executeDerived() const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
