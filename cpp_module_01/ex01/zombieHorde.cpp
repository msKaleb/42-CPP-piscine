/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:39:46 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/08 12:13:15 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0) return (NULL);
	
	Zombie				*horde = new Zombie[N];
	std::stringstream	tmpName;
	
	if (!horde) return (NULL);
	
	for (int i = 0; i < N; i++) {
		tmpName << i + 1;
		horde[i] = Zombie(name + "_" + tmpName.str());
		tmpName.str(std::string());
	}
	
	return (horde);
}
