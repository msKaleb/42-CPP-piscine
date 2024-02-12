#include "Serializer.hpp"

Serializer::Serializer() {
	// std::cout << "Serializer: Default Constructor Called" << std::endl;
}

Serializer::~Serializer() {
	// std::cout << "Serializer: Destructor Called" << std::endl;
}

Serializer::Serializer(Serializer const &copy) {
	// std::cout << "Serializer: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Serializer	&Serializer::operator=(const Serializer &rhs) {
	// std::cout << "Serializer: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}
