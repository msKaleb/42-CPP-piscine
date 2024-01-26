#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : 
						_name(name), _grade(grade) {

	if (this->_grade < 1)
		throw this->GradeTooHighException();
	else if (this->_grade > 150)
		throw this->GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat: Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	// std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	// std::cout << "Bureaucrat: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		const_cast<std::string&>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::string		Bureaucrat::getName(void) const { return this->_name; }

unsigned int	Bureaucrat::getGrade(void) const { return this->_grade; }

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

void	Bureaucrat::incGrade(void) {
	if (this->_grade > 1)
		this->_grade --;
	else
		throw this->GradeTooHighException();
}

void	Bureaucrat::decGrade(void) {
	if (this->_grade < 150)
		this->_grade ++;
	else
		throw this->GradeTooLowException();
}

Bureaucrat::bException	Bureaucrat::GradeTooHighException(void) {
	bException	e;

	return e;
}

Bureaucrat::bException	Bureaucrat::GradeTooLowException(void) {
	bException	e;

	return e;
}

const char* Bureaucrat::bException::what() const throw() {
	return "Invalid grade number";
}
