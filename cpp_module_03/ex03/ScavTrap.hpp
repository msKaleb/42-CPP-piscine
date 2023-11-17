/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:15 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/17 08:36:42 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
protected:
	/* data */
	unsigned int	_scavEnergyPoints;
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &copy);
	virtual ~ScavTrap();

	ScavTrap	&operator=(ScavTrap const &rhs);
	void		attack(const std::string &target);
	void		guardGate(void) const;
};

#endif /* SCAVTRAP_HPP */
