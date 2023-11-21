/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:19:15 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 05:54:54 by msoria-j         ###   ########.fr       */
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
}

std::string const   &AMateria::getType(void) const {
    return this->_type;
}