#include "Intern.hpp"

Intern::Intern() {
	// std::cout << "Intern: Default Constructor Called" << std::endl;
}

Intern::~Intern() {
	// std::cout << "Intern: Destructor Called" << std::endl;
}

Intern::Intern(Intern const &copy) {
	// std::cout << "Intern: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Intern	&Intern::operator=(const Intern &rhs) {
	// std::cout << "Intern: Copy Assignment Operator Called" << std::endl;
	return (*this);
}

const char*	Intern::makeFormException::what() const throw() {
	return RED "Incorrect form name" RESET;
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
	AForm	*(Intern::*functionPtr[])(std::string const &target) = {
		&Intern::shrubbery,
		&Intern::robotomy,
		&Intern::presidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			std::cout << MAGENTA "Intern creates " << formName << RESET << std::endl;
			return ((this->*functionPtr[i])(formTarget));
		}
	}
	throw Intern::makeFormException();
}
