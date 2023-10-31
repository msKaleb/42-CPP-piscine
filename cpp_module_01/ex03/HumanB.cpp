/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:42:27 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/31 11:44:50 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {
}

void	HumanB::attack(void) {
	/* if (!this->_weapon)
		std::cout << "weapon is NULL!" << std::endl; */
	if (this->_weapon == NULL || this->_weapon->getType().empty())
		std::cout << this->_name << " attacks with his fists" << std::endl;
	else
		std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &hWeapon) {
	this->_weapon = &hWeapon;
	return ;
}