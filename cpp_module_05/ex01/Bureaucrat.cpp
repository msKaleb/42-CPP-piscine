#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : 
						_name(name), _grade(grade) {

	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
		this->~Bureaucrat();
		new(this) Bureaucrat(rhs);
	}
	return (*this);
}

std::string const	Bureaucrat::getName(void) const { return this->_name; }

unsigned int	Bureaucrat::getGrade(void) const { return this->_grade; }

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

void	Bureaucrat::incGrade(void) {
	if (this->_grade > 1)
		this->_grade --;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decGrade(void) {
	if (this->_grade < 150)
		this->_grade ++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &f) {
	if (this->_grade <= f.getSignGrade() && !f.getSigned())
		std::cout << GREEN << this->_name << " signed " << f.getName() << RESET << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << f.getName()
			<< " because: ";
	f.beSigned(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Grade too high" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return RED "Grade too low" RESET;
}
