/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:38:28 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 05:38:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure : Default Constructor Called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure : Destructor Called" << std::endl;
}

Cure::Cure(Cure const &copy) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Cure	&Cure::operator=(const Cure &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}
