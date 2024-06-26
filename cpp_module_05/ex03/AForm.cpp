#include "AForm.hpp"

/* AForm::AForm() {
	std::cout << "AForm: Default Constructor Called" << std::endl;
} */

AForm::AForm(std::string name, unsigned int toSign,unsigned int toExecute, std::string const target) :
	_name(name), _signed(false), _signGrade(toSign), _execGrade(toExecute), _target(target), _executed(false) {

		if (_signGrade < 1 || _execGrade < 1)
			throw AForm::GradeTooHighException();
		else if (_signGrade > 150 || _execGrade > 150)
			throw AForm::GradeTooLowException();
	}

AForm::~AForm() {
	// std::cout << "AForm: Destructor Called" << std::endl;
}

AForm::AForm(AForm const &copy) :
	_name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade),
	_execGrade(copy._execGrade), _target(copy._target) {}

AForm	&AForm::operator=(const AForm &rhs) {
	std::cout << "AForm: Copy Assignment Operator Called" << std::endl;

	// "error: 'this' pointer cannot be null in well-defined C++ code"
	// if (!this)
	// 	new AForm(rhs);
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

/* getters */
std::string const	AForm::getName(void) const { return this->_name; }
unsigned int		AForm::getSignGrade(void) const { return this->_signGrade; }
unsigned int		AForm::getSignExec(void) const { return this->_execGrade; }
bool				AForm::getSigned(void) const { return this->_signed; }
std::string const	AForm::getTarget(void) const { return this->_target; }
bool				AForm::getExecuted(void) const { return this->_executed; }

/* setters */
void	AForm::setExecuted(bool status) { this->_executed = status; }

/* exceptions */
const char* AForm::GradeTooHighException::what() const throw() {
	return RED "Grade too high" RESET;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return RED "Grade too low" RESET;
}

const char* AForm::FormAlreadySigned::what() const throw() {
	return RED "The form is already signed" RESET;
}

const char* AForm::FormNotSigned::what() const throw() {
	return RED "Unisgned form cannot be executed" RESET;
}

/* operator override */
std::ostream	&operator<<(std::ostream &o, AForm const &i) {
	std::string	status = i.getSigned() == false? "Not signed" : "Signed";

	o << "Form name: " << i.getName() << "\n" \
		<< "Status: " << status << "\n" \
		<< "Minimum grade to be signed: " << i.getSignGrade() << "\n" \
		<< "Minimum grade to be executed: " << i.getSignExec() << "\n" \
		<< std::setfill('-') << std::setw(40) << "\n";

	return o;
}

void	AForm::beSigned(Bureaucrat &b) {
	if (this->getSigned())
		throw AForm::FormAlreadySigned();
	else if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else if (this->_signed)
		throw AForm::FormAlreadySigned();
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	try {
		if (executor.getGrade() > this->_execGrade)
			throw AForm::GradeTooLowException();
		else if (!this->_signed)
			throw AForm::FormNotSigned();
	}catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return ;
	}
	executeDerived();
}
