/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:39:03 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/27 09:24:34 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
private:
	std::string	_name;
	
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void) const;
	void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */
