/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:05:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/14 09:54:46 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called with name [" << name << "]" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->_name = copy.getName();
	this->operator=(copy);
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

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
		this->_hitPoints = assign.getHitPoints();
		this->_energyPoints = assign.getEnergyPoints();
		this->_attackDamage = assign.getAttackDamage();
	}
	return (*this);
}

// member functions-----------
void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
			<< ", causing " << this->getAttackDamage() << " points of damage"
			<< std::endl;
		this->_energyPoints--;
		return ;
	}
	std::cout << "No energy points left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->getName() << " receives " << amount
			<< " points of damage " << std::endl;
		this->_energyPoints--;
		return ;
	}
	std::cout << "No energy points left" << std::endl;
}

/* void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
			<< ", causing " << this->getAttackDamage() << " points of damage"
			<< std::endl;
		return ;
	}
	std::cout << "No energy points left" << std::endl;
} */
