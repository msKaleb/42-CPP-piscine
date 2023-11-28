/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:38:33 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/28 10:14:52 by msoria-j         ###   ########.fr       */
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

	// segfault
	{
		IMateriaSource	*src = new MateriaSource();
		{
		AMateria		*ice = new Ice();
		AMateria		*cure = new Cure();

		src->learnMateria(ice);
		src->learnMateria(cure);
		delete ice;
		delete cure;
		}

		Character	me("me");
		Character	you("you");
		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me.equip(tmp);
		tmp = src->createMateria("cure");
		me.equip(tmp);
		tmp = src->createMateria("ice");
		me.equip(tmp);
		tmp = src->createMateria("cure");
		me.equip(tmp);

		tmp = src->createMateria("ice");
		you.equip(tmp);
		tmp = src->createMateria("cure");
		you.equip(tmp);
		tmp = src->createMateria("ice");
		you.equip(tmp);
		tmp = src->createMateria("cure");
		you.equip(tmp);

		me.unequip(0);
		me.unequip(0);
		me.unequip(0);
		me.unequip(3);

		me = you;

		you.unequip(0);
		you.unequip(1);
		you.unequip(2);
		you.unequip(3);

		delete src;

		return 0;
	}
	{
		IMateriaSource	*src = new MateriaSource();
		
		// learning materia through 'new Materia()' forces a leak
		/* src->learnMateria(new Ice());
		src->learnMateria(new Cure()); */
		// the proper way is defining pointers that can be deleted manually
		{
		AMateria		*ice = new Ice();
		AMateria		*cure = new Cure();

		src->learnMateria(ice);
		src->learnMateria(cure);
		delete ice;
		delete cure;
		}

		ICharacter	*me = new Character("Me");
		ICharacter	*you = new Character("You");

		AMateria	*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		tmp = src->createMateria("ice");
		you->equip(tmp);
		tmp = src->createMateria("cure");
		you->equip(tmp);
		tmp = src->createMateria("ice");
		you->equip(tmp);
		tmp = src->createMateria("cure");
		you->equip(tmp);

		me->unequip(0);
		me->unequip(0);
		me->unequip(0);
		me->unequip(3);

		you->unequip(0);
		you->unequip(1);
		you->unequip(2);
		you->unequip(3);
		
		ICharacter	*bob = new Character("Bob");
		
		me->use(1, *bob);
		me->use(3, *bob);
		me->use(2, *bob);

		you->use(0, *bob);
		you->use(2, *bob);
		you->use(1, *bob);
		
		delete bob;
		delete me;
		delete you;
		delete src;
	
		return 0;
	}
	ICharacter	*me = new Character("Me");
	ICharacter	*you = new Character("You");
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