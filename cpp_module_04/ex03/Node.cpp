#include "Node.hpp"

Node::Node() {
	std::cout << "Node: Default Constructor Called" << std::endl;
}

// shallow copy wanted, just to store the addresses
// of discarded objects
Node::Node(AMateria *toDiscard) : discarded(toDiscard) {
	this->next = NULL;
}

Node::~Node() {
	std::cout << "Node: Destructor Called" << std::endl;
}

Node::Node(Node const &copy) {
	std::cout << "Node: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Node	&Node::operator=(const Node &rhs) {
	std::cout << "Node: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		// this->discarded = rhs.getMateria();
		this->discarded = rhs.discarded;
		this->next = rhs.next;
	}
	return (*this);
}

/* AMateria	*Node::getMateria(void) const {
	return this->_discarded;
} */