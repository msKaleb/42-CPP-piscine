/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:21:51 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/30 22:53:23 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(/* args */) {
}

Weapon::Weapon(std::string weaponType) : _type(weaponType) {}

Weapon::~Weapon() {
}

std::string	&Weapon::getType() {
	std::string	&typeRef = this->_type;
	return (typeRef);
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}