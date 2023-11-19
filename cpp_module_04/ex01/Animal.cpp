/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:55:27 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 12:55:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(std::string const &type) : _type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal() : _type("Default animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal & src ) : _type(src.getType()) {
	std::cout << "Animal copy constructor called" << std::endl;
	// this->operator=(src);
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
	o << "Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound(void) const { std::cout << "..." << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType(void) const { return this->_type; }

/* ************************************************************************** */