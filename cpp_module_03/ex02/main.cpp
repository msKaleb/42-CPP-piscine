/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/15 19:40:51 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){

	ClapTrap	a("ClatTrap_a");
	ScavTrap	b("ScavTrap_b");
	FragTrap	c("FragTrap_c");
	FragTrap	d(c);

	std::cout << "printing: " << d.getName() << std::endl;
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
	c.highFivesGuys();
	return 0;
}
