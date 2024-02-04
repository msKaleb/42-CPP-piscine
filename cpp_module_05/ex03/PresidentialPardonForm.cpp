#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	AForm("[Presidential Form " + target + "]", 25, 5, target) {
	std::cout << "PresidentialPardonForm: Default Constructor Called" << std::endl;
	// this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) :
	AForm(copy) {
	// std::cout << "PresidentialPardonForm: Copy Constructor Called" << std::endl;
	// if (this != &copy)
	// 	this->setTarget(copy.getTarget());
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	std::cout << "PresidentialPardonForm: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->~PresidentialPardonForm();
		new(this) PresidentialPardonForm(rhs.getTarget());
	}
	return (*this);
}

void	PresidentialPardonForm::executeDerived() const {
	/* if (!this->getExecuted())
		return ; */
	try {
		std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
