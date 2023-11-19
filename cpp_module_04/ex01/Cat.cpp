/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:27:00 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 17:49:08 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), _brain(new Brain()) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->operator=(src);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs) {
	std::cout << "Cat assignment operator called" << std::endl;
	if ( this != &rhs ) {
		*this->_brain = *rhs.getBrain();	// deep copy
		// this->_brain = rhs.getBrain();	// shallow copy
		this->Animal::operator=(rhs);
	}
	return *this;
}

Brain	*Cat::getBrain(void) const {
	return this->_brain;
}
