/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:06 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/24 16:45:59 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <iomanip>

class Zombie
{
private:
	std::string	_name;
	
public:
	// Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void) const;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif /* ZOMBIE_HPP */
