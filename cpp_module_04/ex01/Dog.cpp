/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:35:09 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 17:20:57 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src), _brain(new Brain()) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->operator=(src);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignment operator called" << std::endl;
	if ( this != &rhs ) {
		*this->_brain = *rhs.getBrain();	// deep copy
		// this->_brain = rhs.getBrain();	// shallow copy
		this->Animal::operator=(rhs);
	}
	return *this;
}

Brain	*Dog::getBrain(void) const {
	return this->_brain;
}
