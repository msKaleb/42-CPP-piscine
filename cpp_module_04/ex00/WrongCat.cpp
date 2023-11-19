/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:31 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 13:09:15 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	// this->operator=(src);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if ( this != &rhs ) {
		// this->_type = rhs.getType();
		this->WrongAnimal::operator=(rhs);
	}
	return *this;
}