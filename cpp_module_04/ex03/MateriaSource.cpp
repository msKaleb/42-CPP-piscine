/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:13 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 09:30:14 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource: Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource: Destructor Called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	std::cout << "MateriaSource: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs) {
	std::cout << "MateriaSource: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}
