#include "Form.hpp"

Form::Form() {
	std::cout << "Form: Default Constructor Called" << std::endl;
}

Form::~Form() {
	std::cout << "Form: Destructor Called" << std::endl;
}

Form::Form(Form const &copy) {
	std::cout << "Form: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Form	&Form::operator=(const Form &rhs) {
	std::cout << "Form: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}
