#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default Constructor Called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern: Destructor Called" << std::endl;
}

Intern::Intern(Intern const &copy) {
	std::cout << "Intern: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Intern	&Intern::operator=(const Intern &rhs) {
	std::cout << "Intern: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

AForm	*Intern::shrubbery(std::string const &formTarget) {
	return new ShrubberyCreationForm(formTarget);
}

AForm	*Intern::robotomy(std::string const &formTarget) {
	return new RobotomyRequestForm(formTarget);
}

AForm	*Intern::presidential(std::string const &formTarget) {
	return new PresidentialPardonForm(formTarget);
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &formTarget) {
	// string of available forms
	std::string	formTypes[] = {
		std::string("shrubbery creation"),
		std::string("robotomy request"),
		std::string("presidential pardon")
	};
	// pointer to functions array
	AForm	*(Intern::*funct[])(std::string const &target) = {
		&Intern::shrubbery,
		&Intern::robotomy,
		&Intern::presidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			return ((this->*funct[i])(formTarget));
		}
	}
	// try-catch block?
	return NULL;
}
