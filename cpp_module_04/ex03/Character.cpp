/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/22 20:48:51 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character() {
// 	std::cout << "Character : Default Constructor Called" << std::endl;
// }

int	Character::_discarded = 0;
Node *Character::_head = NULL;
Node *Character::_current = NULL;

Character::Character(std::string name) : 
	_name(name), _inventory(new AMateria *[4]), _slots(0) {

	std::cout << "Character: Parametrized Constructor Called with name " 
		<< this->_name << std::endl;

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
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
	if (idx < 0 || idx > 3) return ;
	
	// leave on the floor (save the address)
	// Node	*discardedMateria = new Node(this->_inventory[idx]);
	// Node	*discardedMateria = NULL;
	// discardedMateria->discarded = this->_inventory[idx];
	
	if (!this->_inventory[idx]) {
		std::cout << "* Slot [" << idx << "] is already empty *" << std::endl;
		return ;
	}
	// Character::_current->discarded = this->_inventory[idx];
	if (Character::_discarded == 0) {
		// Character::_head = discardedMateria;
		Character::_head = new Node(this->_inventory[idx]);
		Character::_current = _head;
	}
	else {
		while (Character::_current->next != NULL)
			Character::_current = Character::_current->next;
		Character::_current->next = new Node(this->_inventory[idx]);
	}
	this->_inventory[idx] = NULL;
	std::cout << "* Slot [" << idx << "] unequipped *" << std::endl;
	Character::_discarded++;
	
	// should I have to decrement _slots and rearrange _inventory???
	// ...
}

void	Character::use(int idx, ICharacter &target) {
	// only from 0 to 3
	if (idx < 0 || idx > 3) return ;
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