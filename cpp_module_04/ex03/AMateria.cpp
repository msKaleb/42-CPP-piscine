/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:19:15 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 12:15:55 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(/* args */) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &copy) {
    if (this != &copy)
        this->operator=(copy);
}

AMateria    &AMateria::operator=(AMateria const &rhs) {
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

std::string const   &AMateria::getType(void) const {
    return this->_type;
}

void    AMateria::use(ICharacter &target) {
    std::cout << "AMateria use " << target.getName() << std::endl;
}

/* void	AMateria::use(ICharacter &target) {
    if (this->getType() == "ice") {
        std::cout << "* shoots an ice bolt at "
            << target.getName() << " *" << std::endl;
    }
    else if (this->getType() == "cure") {
        std::cout << " * heals " << target.getName()
            << "'s wounds *" << std::endl;
    }
} */
