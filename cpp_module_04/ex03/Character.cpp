/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 16:05:07 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character() {
// 	std::cout << "Character : Default Constructor Called" << std::endl;
// }

Character::Character(std::string name) : _name(name), _inventory(new AMateria *[4]) {
	std::cout << "Character: Parametrized Constructor Called with name " 
		<< this->_name << std::endl;
	this->_slots = 0;
	/* for (int i = 0; i < 4; i++) {
		this->_inventory[i] = new Ice();
	} */
}

Character::~Character() {
	std::cout << "Character: Destructor Called" << std::endl;
	for (int i = 0; i < this->_slots; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	delete [] this->_inventory;
}
// check
Character::Character(Character const &copy) :
	_name(copy.getName()), _inventory(new AMateria *[4]), _slots(copy.getSlotsCount()) {

	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < copy.getSlotsCount(); i++) {
			// this->_inventory[i] = copy.getSlot(i); // shallow
			this->_inventory[i] = copy.getSlot(i)->clone(); // deep
		}
	}
}
// implement
Character	&Character::operator=(const Character &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		// delete the current character
		this->~Character();
		new(this) Character(rhs);
	}
	return (*this);
}

std::string const	&Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria *m) {
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
	// should I delete the used materia?
	if (!this->_inventory[idx]) {
		std::cout << "* Slot [" << idx << "] is empty *" << std::endl;
		return ;
	}
	
	this->_inventory[idx]->use(target);
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;

}

int	Character::getSlotsCount(void) const {
	return this->_slots;
}

AMateria	*Character::getSlot(int idx) const {
	return this->_inventory[idx];
}