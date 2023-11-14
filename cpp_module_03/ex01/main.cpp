/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/14 20:45:27 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(){

	ClapTrap	a("ClatTrap_a");
	ScavTrap	b("ScavTrap_b");
	ScavTrap	c("ScavTrap_c");

	a.attack("target");
	b.attack("target");
	b.setEnergyPoints(5);
	for (int i = 0; i < 20; i++) {
		c.takeDamage(10);
		a.takeDamage(10);
		b.beRepaired(1);
		a.attack("target");
	}
	c.attack("target");
	c.guardGate();
	return 0;
}
