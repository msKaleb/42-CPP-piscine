/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/12/03 16:03:35 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character() {
// 	std::cout << "Character : Default Constructor Called" << std::endl;
// }

// initialize static variables
Node	*Character::_head = NULL;
Node	*Character::_current = NULL;
int		Character::_discarded = 0;
int		Character::_characterCount = 0;

Character::Character(std::string name) : 
	_name(name), _inventory(new AMateria *[4]), _slots(0) {

	/* std::cout << "Character: Parametrized Constructor Called with name " 
		<< this->_name << std::endl; */

	// initialise all slots to NULL
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	Character::_characterCount++;
}

Character::~Character() {
	// std::cout << "Character: Destructor Called" << std::endl;
	Character::_characterCount--; // decrement character count

	// delete character's inventory
	for (int i = 0; i < this->_slots; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	delete [] this->_inventory;

	// if there are no characters left, delete the items on the floor
	if (Character::_characterCount == 0) {
		while (Character::_head != NULL) {
			Character::_current = Character::_head->next;
			delete Character::_head->discarded;
			delete Character::_head;
			Character::_head = Character::_current;
			Character::_discarded--;
		}
	}
}
// check ---------------------------------------
Character::Character(Character const &copy) :
	_name(copy.getName()), _inventory(new AMateria *[4]), _slots(copy.getSlotsCount()) {

	// std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy) {
		// initialise all slots to NULL
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = NULL;

		for (int i = 0; i < copy.getSlotsCount(); i++) {
			// this->_inventory[i] = copy.getSlot(i); // shallow
			this->_inventory[i] = copy.getSlot(i)->clone(); // deep copy needed
		}
		Character::_characterCount++;
	}
}

Character	&Character::operator=(const Character &rhs) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		// unequip everything
		/* for (int i = 0; i < this->getSlotsCount(); i++) {
			this->unequip(i);
		} */

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
	// check if the materia exists
	if (!m) return;
	/* std::cout << this->getName() << " equips " 
		<< m->getType() << std::endl; */
	// if the inventory is full, do nothing
	if (this->_slots == 4) return ;
	// shallow copy, don't have to duplicate it
	this->_inventory[this->_slots] = m;
	this->_slots++;
}

// leave on the floor (save the address)
void	Character::unequip(int idx) {
	// return if out of bounds
	if (idx < 0 || idx > 3) return ;
	// check if it's already empty (NULL)
	if (!this->_inventory[idx]) {
		// std::cout << "* Slot [" << idx << "] is already empty *" << std::endl;
		return ;
	}
	// if it's the first discarded item, make it the head of the list
	if (Character::_discarded == 0) {
		Character::_head = new Node(this->_inventory[idx]);
		Character::_current = _head;
	}
	// else, add it to the last element of the list
	else {
		while (Character::_current->next != NULL)
			Character::_current = Character::_current->next;
		Character::_current->next = new Node(this->_inventory[idx]);
	}
	// make the slot empty
	this->_inventory[idx] = NULL;
	// std::cout << "* Slot [" << idx << "] unequipped *" << std::endl;
	Character::_discarded++;
}

void	Character::use(int idx, ICharacter &target) {
	// only from 0 to 3
	if (idx < 0 || idx > 3) return ;
	if (!this->_inventory[idx]) {
		std::cout << "* Slot [" << idx << "] is empty *" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);

	// should I delete the used materia?
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

int	Character::getSlotsCount(void) const {
	return this->_slots;
}

AMateria	*Character::getSlot(int idx) const {
	return this->_inventory[idx];
}
