/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/24 14:13:40 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	this->announce();
}

Zombie::~Zombie()
{

}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
