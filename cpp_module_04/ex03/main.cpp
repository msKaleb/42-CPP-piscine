/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:38:33 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/22 20:47:50 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void) {
	/* {
		Character	*me = new Character("Mikel");
		Character	*you = new Character("Marta");

		me->equip(new Ice());
		*me = *you;
		delete me;
		delete you;

		return 0;
	} */
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter	*me = new Character("Mikel");

		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(5);
		
		ICharacter	*bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(3, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	
		// floor->~Node(); // cleanup?
		
		return 0;
	}
	ICharacter	*me = new Character("Mikel");
	ICharacter	*you = new Character("Marta");
	AMateria	*ice = new Ice();
	AMateria	*cloneMe;
	
	cloneMe = ice->clone();
	std::cout << cloneMe->getType() << std::endl;
	std::cout << me->getName() << std::endl;
	std::cout << you->getName() << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());

	me->use(2, *you);
	delete me;
	delete you;
	delete ice;
	delete cloneMe;
}