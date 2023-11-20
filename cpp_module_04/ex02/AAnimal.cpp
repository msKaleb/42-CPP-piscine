/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:55:27 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 12:55:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(std::string const &type) : _type(type) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal() : _type("Default AAnimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ) : _type(src.getType()) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	// this->operator=(src);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal	&AAnimal::operator=( AAnimal const &rhs ) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i ) {
	o << "Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound(void) const { std::cout << "..." << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AAnimal::getType(void) const { return this->_type; }

/* ************************************************************************** */