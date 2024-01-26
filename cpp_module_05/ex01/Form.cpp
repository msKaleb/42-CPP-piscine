#include "Form.hpp"

Form::Form() {
	std::cout << "Form: Default Constructor Called" << std::endl;
}

Form::Form(std::string name, unsigned int toSign, unsigned int toExecute) :
	_name(name), _signed(false), _signGrade(toSign), _execGrade(toExecute) {

		if (_signGrade < 1 || _execGrade < 1)
			throw this->GradeTooHighException();
		else if (_signGrade > 150 || _execGrade > 150)
			throw this->GradeTooLowException();
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

std::string		Form::getName(void) const { return this->_name; }
bool			Form::getSigned(void) const { return this->_signed; }
unsigned int	Form::getSignGrade(void) const { return this->_signGrade; }
unsigned int	Form::getSignExec(void) const { return this->_execGrade; }

bException	Form::GradeTooHighException(void) {
	return bException();
}

bException	Form::GradeTooLowException(void) {
	return bException();
}

std::ostream	&operator<<(std::ostream &o, Form const &i) {
	std::string	status = i.getSigned() == false? "Not signed" : "Signed";

	o << "Form name: " << i.getName() << "\n" \
		<< "Status: " << status << "\n" \
		<< "Minimum grade to be signed: " << i.getSignGrade() << "\n" \
		<< "Minimum grade to be executed: " << i.getSignExec();

	return o;
}

void	Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_signGrade)
		throw this->GradeTooLowException();
	else
		this->_signed = true;
}
