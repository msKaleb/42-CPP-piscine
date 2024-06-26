/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:41:56 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/31 11:28:19 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& hWeapon) : _name(name), _weapon(hWeapon) {}

HumanA::~HumanA() {
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}
