/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/16 13:05:54 by msoria-j         ###   ########.fr       */
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
	DiamondTrap	e("Monster");

	std::cout << "ScavTrap Energy Points: " << b.getEnergyPoints() << std::endl;
	b.attack("bTarget");

	e = d;
	e.whoAmI();
	
	std::cout << d << std::endl;
	for (int i = 0; i < 100; i++)
		d.attack("dTarget");
	for (int i = 0; i < 100; i++)
		d.takeDamage(2);
	
	d.setEnergyPoints(10);
	d.beRepaired(5);
	d.setHitPoints(20);
	d.beRepaired(5);
	std::cout << d << std::endl;

	b.guardGate();
	c.highFivesGuys();
	return 0;
}
