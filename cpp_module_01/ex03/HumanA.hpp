/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:41:13 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/31 09:44:43 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		/* data */
		std::string	_name;
		Weapon&		_weapon;
	public:
		HumanA(std::string name, Weapon& hWeapon);
		~HumanA();

		void	attack(void);
};

#endif /* HUMANA_HPP */