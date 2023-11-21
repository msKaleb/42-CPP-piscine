/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 12:22:59 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character() {
// 	std::cout << "Character : Default Constructor Called" << std::endl;
// }

Character::Character(std::string name) : _name(name), _inventory(new AMateria *[4] ) {
	std::cout << "Character : Parametrized Constructor Called with name " 
		<< this->_name << std::endl;
	this->_slots = 0;
	/* for (int i = 0; i < 4; i++) {
		this->_inventory[i] = new Ice();
	} */
}

Character::~Character() {
	std::cout << "Character : Destructor Called" << std::endl;
	for (int i = 0; i < this->_slots; i++)
		delete this->_inventory[i];
	delete [] this->_inventory;
}

Character::Character(Character const &copy) : _name(copy.getName()) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Character	&Character::operator=(const Character &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		// since _name is a const reference, const_cast<type&> is needed
		const_cast<std::string&>(this->_name) = rhs.getName();
	}
	return (*this);
}

std::string const	&Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria *m) {
	(void)m;
	std::cout << this->getName() << " equips " 
		<< m->getType() << std::endl;
	if (this->_slots == 3) return ;
	this->_inventory[this->_slots] = m; // shallow copy
	this->_slots++;
}

void	Character::unequip(int idx) {
	std::cout << "unequip " << idx << std::endl;
}

void	Character::use(int idx, ICharacter &target) {
	// std::cout << "use " << idx << " on " << target.getName() << std::endl;
	this->_inventory[idx]->use(target);
}
