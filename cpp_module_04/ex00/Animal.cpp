#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Default animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal & src ) {
	std::cout << "Animal copy constructor called" << std::endl;
	Animal::operator=(src);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal	&Animal::operator=( Animal const &rhs ) {
	std::cout << "Animal assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i ) {
	o << "Type: " << i.getType() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound(void) const {}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType(void) const { return this->_type; }

/* ************************************************************************** */