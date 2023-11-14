/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/14 09:55:17 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){

	ClapTrap	a("Mikel");
	ClapTrap	b(a);
	ClapTrap	c("Paco");

	b.setHitPoints(5);
	std::cout << a.getHitPoints() << std::endl;
	std::cout << b.getHitPoints() << std::endl;
	b.attack("Paco");
	b.setAttackDamage(5);
	for (int i = 0; i < 12; i++) {
		b.attack("Paco");
		b.takeDamage(6);
	}
	return 0;
}
