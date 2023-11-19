#include "Brain.hpp"
#include <sstream>	// to append a number to a string

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() : _ideas(new std::string[100]) {
	std::stringstream	tmpName;

	std::cout << "Brain constructor called" << std::endl;
	// Fill in the ideas array
	for (int i = 0; i < 100; i++) {
		tmpName << i + 1;
		this->_ideas[i] = "Idea number " + tmpName.str();
		tmpName.str(std::string());
	}
}

Brain::Brain( const Brain & src ) : _ideas(new std::string[100]) {
	std::cout << "Brain copy constructor called" << std::endl;
	this->operator=(src);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	delete [] _ideas;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain	&Brain::operator=( Brain const &rhs )
{
	std::cout << "Brain assignment operator called" << std::endl;
	if ( this != &rhs ) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdeas()[i];
	}
	return *this;
}

std::ostream	&operator<<( std::ostream & o, Brain const &i )
{
	for (int k = 0; k < 100; k++) {
		o << i.getIdeas()[k] << std::endl; 
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	*Brain::getIdeas(void) const {
	return this->_ideas;
}

/* ************************************************************************** */