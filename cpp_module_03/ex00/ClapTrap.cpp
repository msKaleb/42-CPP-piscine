/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:05:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/13 15:29:13 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called with name [" << name << "]" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
}

// getters------------
unsigned int	ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

unsigned int	ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

unsigned int	ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }

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