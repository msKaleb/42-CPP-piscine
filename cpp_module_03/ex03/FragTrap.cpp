/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:56:29 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/16 22:55:46 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << CYAN << "Fragtrap constructor called with name [" 
		<< name << "]" << std::endl << RESET;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	/* this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100); */
}

FragTrap::~FragTrap() {
	std::cout << BLUE << "FragTrap destructor called for [" 
		<< this->getName() << "]" << std::endl << RESET;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout << CYAN << "FragTrap copy constructor called for [" 
		<< this->getName() << "]" << std::endl << RESET;
}

void	FragTrap::highFivesGuys(void) const {
	if (this->_energyPoints > 0 &&  this->_hitPoints > 0) {
		std::cout << BOLDWHITE << "FragTrap " << this->getName()
			<< " says: Give me five!" << std::endl << RESET;
	}
	else
		std::cout << WHITE << "No energy / hit points left" << std::endl << RESET;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}
