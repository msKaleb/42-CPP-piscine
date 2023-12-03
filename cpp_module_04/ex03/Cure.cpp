/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:38:28 by msoria-j          #+#    #+#             */
/*   Updated: 2023/12/03 16:01:56 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure: Default Constructor Called" << std::endl;
}

Cure::~Cure() {
	// std::cout << "Cure: Destructor Called" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy) {
	// std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy) {
		*this = copy;
	}
}

Cure	&Cure::operator=(const Cure &rhs) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->~Cure();
		new(this) Cure();
	}
	return (*this);
}

AMateria	*Cure::clone() const {
	return new Cure();
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName()
				<< "'s wounds *" << std::endl;
}