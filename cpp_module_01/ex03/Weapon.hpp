/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:32:57 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/30 22:43:09 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(/* args */);
		Weapon(std::string weaponType);
		~Weapon();

		std::string	&getType();
		void	setType(std::string newType);
};

#endif /* WEAPON_HPP */
