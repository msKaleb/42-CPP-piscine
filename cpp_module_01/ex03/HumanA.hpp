/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:41:13 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/30 22:49:13 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
		/* data */
		std::string	_name;
		Weapon		_weapon;
	public:
		HumanA(std::string name, Weapon hWeapon);
		~HumanA();

		void	attack(void);
};


