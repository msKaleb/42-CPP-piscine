/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:05:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:51 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << CYAN << "Constructor called with name [" << name << "]" << std::endl << RESET;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << CYAN << "Copy constructor called" << std::endl << RESET;
	this->operator=(copy);
}

ClapTrap::~ClapTrap() { std::cout << BLUE << "Destructor called for [" << this->getName() << "]" << std::endl << RESET; }

// getters------------
unsigned int	ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

unsigned int	ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

unsigned int	ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }

std::string		ClapTrap::getName(void) const { return (this->_name); }

// setters------------
void	ClapTrap::setHitPoints(unsigned int qty) { this->_hitPoints = qty; }

void	ClapTrap::setEnergyPoints(unsigned int qty) { this->_energyPoints = qty; }

void	ClapTrap::setAttackDamage(unsigned int qty) { this->_attackDamage = qty; }

// operators overload
ClapTrap	&ClapTrap::operator=(ClapTrap const &assign) {
	if (this != &assign) {	
		this->_name = assign.getName();
		this->_hitPoints = assign.getHitPoints();
		this->_energyPoints = assign.getEnergyPoints();
		this->_attackDamage = assign.getAttackDamage();
	}
	return (*this);
}

// member functions-----------
void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 &&  this->_hitPoints > 0) {
		std::cout << YELLOW << "ClapTrap "  << this->getName() << " attacks " << target
			<< ", causing " << this->getAttackDamage() << " points of damage"
			<< std::endl << RESET;
		if (this->_energyPoints > 0)
			this->_energyPoints--;
		return ;
	}
	if (this->_hitPoints == 0 && this->_energyPoints == 0)
		std::cout << BOLDYELLOW<< this->getName() 
			<< " can't attack. No energy / hit points left" << std::endl << RESET;
	else if (this->_hitPoints == 0)
		std::cout << BOLDYELLOW<< this->getName() 
			<< " can't attack. No hit points left" << std::endl << RESET;
	else
		std::cout << BOLDYELLOW<< this->getName() 
			<< " can't attack. No energy points left" << std::endl << RESET;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		// check if it's about to die
		if ((int)(this->_hitPoints - amount) < 0) this->_hitPoints = 0;
		else this->_hitPoints -= amount;
		// print message
		std::cout << RED << this->getName() << " receives " << amount
			<< " points of damage. Life: " << this->getHitPoints() << std::endl << RESET;
		return ;
	}
	std::cout << BOLDRED << this->getName() 
		<< " is already dead. Can't take any more damage" << std::endl << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_hitPoints += amount;
		std::cout << GREEN << this->getName() << " gets "
			<< amount << " hit points back, for a total of "
			<< this->_hitPoints << " hit points" << std::endl << RESET;
		if (this->_energyPoints > 0)
			this->_energyPoints--;
		return ;
	}
	if (this->_energyPoints == 0)
		std::cout << BOLDGREEN << "Can't be repaired. No energy points left" << std::endl << RESET;
	else if (this->_hitPoints == 0)
		std::cout << BOLDGREEN << this->getName() 
			<< " is already dead. Can't be repaired" << std::endl << RESET;
}
