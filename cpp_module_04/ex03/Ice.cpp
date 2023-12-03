#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice: Default Constructor Called" << std::endl;
}

Ice::~Ice() {
// 	std::cout << "Ice: Destructor Called" << std::endl;
}

Ice::Ice(Ice const &obj) : AMateria(obj) {
	// std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj; // operator= ??
}
// TO BE IMPLEMENTED
Ice	&Ice::operator= (const Ice &obj) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

AMateria	*Ice::clone() const {
	AMateria	*ret = new Ice();

	// clone things - deep copy
	// ret->attributes = this->attributes
	return ret;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
