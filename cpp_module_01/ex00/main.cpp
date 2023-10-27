/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:09:36 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/26 19:52:32 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*ptrZombie, *ptrZ2 = NULL;

	randomChump("stackZombie");
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	ptrZombie = newZombie("heapZombie");
	ptrZombie->announce();
	ptrZ2 = newZombie("secondHeapZombie");
	ptrZ2->announce();
	delete (ptrZombie);
	delete (ptrZ2);
	return (0);
}
