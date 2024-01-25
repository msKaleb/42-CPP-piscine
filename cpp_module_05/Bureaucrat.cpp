#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : 
						_name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << "Bureaucrat: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

std::string		Bureaucrat::getName(void) const { return this->_name; }

unsigned int	Bureaucrat::getGrade(void) const { return this->_grade; }

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

void	Bureaucrat::incGrade(void) {this->_grade --; }

void	Bureaucrat::decGrade(void) {this->_grade ++; }
