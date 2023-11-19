/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:11:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 13:42:43 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	// WrongAnimal test
	/* {
		const WrongAnimal	*meta = new WrongAnimal();
		const WrongAnimal	*i = new WrongCat();
		const WrongCat		*j = new WrongCat();

		std::cout << std::setfill('-') << std::setw(40)  << '\n';
		std::cout << *meta << std::endl;
		std::cout << *i << std::endl;
		std::cout << *j << std::endl;
		std::cout << std::setfill('-') << std::setw(40)  << '\n';
		
		std::cout << "---Making noises---" << std::endl;
		std::cout << "meta as WrongAnimal: ";
		meta->makeSound();
		std::cout << "i as WrongAnimal: ";
		i->makeSound();
		std::cout << "j as WrongCat: ";
		j->makeSound();
		std::cout << std::setfill('-') << std::setw(40)  << '\n';
		
		delete meta;
		delete i;
		delete j;

		return 0;
	} */
	// subject main example
	/* {
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
		
		return 0;
	} */

	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();
	Animal			a, b, c(*j);

	b = *i;
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	
	std::cout << "meta: " << *meta << std::endl;
	std::cout << "i: " << *i << std::endl;
	std::cout << "j: " << *j << std::endl;
	
	std::cout << "---Making noises---" << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	
	delete meta;
	delete i;
	delete j;
	
	return 0;
}