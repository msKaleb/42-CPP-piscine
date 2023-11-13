/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:18 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/13 16:23:34 by msoria-j         ###   ########.fr       */
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
	return 0;
}
