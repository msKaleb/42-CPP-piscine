/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/14 12:08:50 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){

	ClapTrap	a("Mikel");
	ClapTrap	b("Mikeltxo");
	ClapTrap	c("Paco");

	b.setHitPoints(7);
	std::cout << a.getName() <<": " << a.getHitPoints() << " hitpoints" << std::endl;
	std::cout << b.getName() <<": " << b.getHitPoints() << " hitpoints" << std::endl;
	b.attack("Paco");
	b.setAttackDamage(5);
	for (int i = 0; i < 6; i++) {
		b.attack("Paco");
		b.takeDamage(6);
		b.beRepaired(7);
	}
	return 0;
}
