/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/16 11:46:48 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(){

	ClapTrap	a("ClatTrap_a");
	ScavTrap	b("ScavTrap_b");
	FragTrap	c("FragTrap_c");
	DiamondTrap	d("DiamondTrap_test");

	std::cout << "ScavTrap Energy Points: " << b.getEnergyPoints() << std::endl;
	b.attack("bTarget");
/* 	std::cout << "DiamondTrap name: " << d.getName() << std::endl;
	std::cout << "DiamondTrap clapTrapName: " << d.getClapTrapName() << std::endl;
	std::cout << "DiamondTrap Hit Points: " << d.getHitPoints() << std::endl;
	std::cout << "DiamondTrap Energy Points: " << d.getEnergyPoints() << std::endl;
	std::cout << "DiamondTrap Attack Damage: " << d.getAttackDamage() << std::endl; */

	d.setHitPoints(25);
	std::cout << d << std::endl;
	
	for (int i = 0; i < 100; i++)
		d.attack("dTarget");
	for (int i = 0; i < 100; i++)
		d.takeDamage(1);
	d.beRepaired(5);
	// d.setHitPoints(20);
	// d.setEnergyPoints(10);
	d.beRepaired(5);
	std::cout << d << std::endl;
	/* std::cout << "printing: " << d.getName() << std::endl;
	d.setHitPoints(1);
	std::cout << "d.HitPoints: " << d.getHitPoints() << std::endl;
	
	a.attack("target");
	b.attack("target");
	b.setEnergyPoints(5);
	c.attack("target");
	for (int i = 0; i < 20; i++) {
		c.takeDamage(10);
		a.takeDamage(10);
		b.beRepaired(1);
	 	a.attack("target");
	 	c.attack("target");
	}
	c.setHitPoints(40);
	c.beRepaired(10);
	c.attack("target");
	b.guardGate();
	c.highFivesGuys(); */
	return 0;
}
