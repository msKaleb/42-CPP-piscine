#include "Form.hpp"

/* Form::Form() {
	std::cout << "Form: Default Constructor Called" << std::endl;
} */

Form::Form(std::string name, unsigned int toSign, unsigned int toExecute) :
	_name(name), _signed(false), _signGrade(toSign), _execGrade(toExecute) {

		if (_signGrade < 1 || _execGrade < 1)
			throw Form::GradeTooHighException();
		else if (_signGrade > 150 || _execGrade > 150)
			throw Form::GradeTooLowException();
	}

Form::~Form() {
	// std::cout << "Form: Destructor Called" << std::endl;
}

Form::Form(Form const &copy) :
	_name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

Form	&Form::operator=(const Form &rhs) {
	std::cout << "Form: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->~Form();
		new(this) Form(rhs);
	}
	return (*this);
}

/* getters */
std::string const	Form::getName(void) const { return this->_name; }
unsigned int		Form::getSignGrade(void) const { return this->_signGrade; }
unsigned int		Form::getSignExec(void) const { return this->_execGrade; }
bool				Form::getSigned(void) const { return this->_signed; }

const char* Form::GradeTooHighException::what() const throw() {
	return RED "Grade too high" RESET;
}

const char* Form::GradeTooLowException::what() const throw() {
	return RED "Grade too low" RESET;
}

const char* Form::FormAlreadySigned::what() const throw() {
	return RED "The form is already signed" RESET;
}

std::ostream	&operator<<(std::ostream &o, Form const &i) {
	std::string	status = i.getSigned() == false? "Not signed" : "Signed";

	o << "Form name: " << i.getName() << "\n" \
		<< "Status: " << status << "\n" \
		<< "Minimum grade to be signed: " << i.getSignGrade() << "\n" \
		<< "Minimum grade to be executed: " << i.getSignExec() << "\n"
		<< std::setfill('-') << std::setw(40) << "\n";

	return o;
}

void	Form::beSigned(Bureaucrat &b) {
	if (this->getSigned())
		throw Form::FormAlreadySigned();
	else if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (this->_signed)
		throw Form::FormAlreadySigned();
	else
		this->_signed = true;
}
