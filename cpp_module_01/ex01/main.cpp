/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:38:41 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/27 09:26:53 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int		N = 4;
	Zombie	*horde = zombieHorde(N, "zombie");
	
	if (!horde) return (std::cout << "No horde was created" << std::endl, 1);
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
