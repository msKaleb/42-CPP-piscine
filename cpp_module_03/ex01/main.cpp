/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/14 16:02:32 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(){

	ClapTrap	a("Mikel");
	ScavTrap	b("Mikeltxo");
	ScavTrap	c("Paco");

	a.attack("target");
	b.attack("target");
	
	for (int i = 0; i < 51; i++) {
		c.takeDamage(10);
		b.beRepaired(1);
		a.attack("target");
	}
	c.attack("target");
	c.guardGate();
	return 0;
}
