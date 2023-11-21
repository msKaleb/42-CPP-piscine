/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:38:33 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 12:31:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void) {
	ICharacter	*me = new Character("Mikel");
	ICharacter	*you = new Character("Marta");

	std::cout << me->getName() << std::endl;
	std::cout << you->getName() << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());

	me->use(2, *you);
	delete me;
	delete you;
}