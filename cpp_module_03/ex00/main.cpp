/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/16 12:02:09 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){

	ClapTrap	a("CTA");
	ClapTrap	b("CTB");
	ClapTrap	c("CTC");

	b.setHitPoints(7);
	std::cout << a.getName() <<": " << a.getHitPoints() << " hitpoints" << std::endl;
	std::cout << b.getName() <<": " << b.getHitPoints() << " hitpoints" << std::endl;
	b.attack("CTC");
	b.setAttackDamage(5);
	for (int i = 0; i < 6; i++) {
		b.attack("CTC");
		b.takeDamage(6);
		b.beRepaired(7);
	}
	return 0;
}
