/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 06:09:22 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character : Default Constructor Called" << std::endl;
}

Character::~Character() {
	std::cout << "Character : Destructor Called" << std::endl;
}

Character::Character(Character const &copy) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Character	&Character::operator=(const Character &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}
