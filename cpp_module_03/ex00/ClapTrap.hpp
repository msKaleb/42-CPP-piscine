/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:56:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/13 16:54:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		// default constructor is private because is useless, but it has to be Canonical
		ClapTrap();

	public:

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();

		ClapTrap	&operator=(ClapTrap const &assign);

		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		std::string		getName(void) const;
		
		void	setHitPoints(unsigned int qty);
		void	setEnergyPoints(unsigned int qty);
		void	setAttackDamage(unsigned int qty);
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_HPP */
