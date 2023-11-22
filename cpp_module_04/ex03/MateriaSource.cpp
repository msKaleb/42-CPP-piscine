/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:13 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 16:03:54 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : _sources(new AMateria *[4]), _sourceCounter(0) {
	std::cout << "MateriaSource: Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource: Destructor Called" << std::endl;
	for (int i = 0; i < this->_sourceCounter; i++)
		delete this->_sources[i];
	delete [] this->_sources;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	std::cout << "MateriaSource: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}
// implement
MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs) {
	std::cout << "MateriaSource: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m) {
	if (this->_sourceCounter == 3) return ;
	this->_sources[this->_sourceCounter] = m; //m->clone();
	this->_sourceCounter++;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < this->_sourceCounter; i++) {
		if (type == this->_sources[i]->getType()) {
			if (type == "ice") return (new Ice());
			else if (type == "cure") return (new Cure());
		}
	}
	return 0;
}