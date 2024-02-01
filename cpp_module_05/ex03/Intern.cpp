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
