/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:54:26 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/15 19:45:02 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << CYAN << "ScavTrap constructor called with name [" 
		<< name << "]" << std::endl << RESET;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::~ScavTrap() {
	std::cout << BLUE << "ScavTrap destructor called for [" 
		<< this->getName() << "]" << std::endl << RESET;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	std::cout << CYAN << "ScavTrap copy constructor called for [" 
		<< this->getName() << "]" << std::endl << RESET;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 &&  this->_hitPoints > 0) {
		std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks " 
			<< target << ", causing " << this->getAttackDamage()
			<< " points of damage" << std::endl << RESET;
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

void	ScavTrap::guardGate(void) const{
	if (this->_energyPoints > 0 &&  this->_hitPoints > 0) {
		std::cout << BOLDWHITE << "ScavTrap " << this->getName()
			<< " is in Gate Keeper mode" << std::endl << RESET;
	}
	else
		std::cout << WHITE << "No energy / hit points left" << std::endl << RESET;
}
