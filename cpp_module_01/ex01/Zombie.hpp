/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:39:03 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/25 17:49:44 by msoria-j         ###   ########.fr       */
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

Zombie	*zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */
