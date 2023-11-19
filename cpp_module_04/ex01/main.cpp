/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:54:57 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 17:31:50 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
/* {	// deep copy test
	Dog	a;
	{
		Dog	b = a;
	}
	std::cout << a.getBrain()->getIdeas()[0] << " - "
		<< a.getType() << std::endl;

	return 0;
} */
/* {	// subject test
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	return 0;
} */
{	// my test
	const Animal	*array[10];

	// fill in the array
	for (int i = 0; i < 10; i++) {
		if (i % 2) // even number
			array[i] = new Cat();
		else // odd number
			array[i] = new Dog();
	}
	
	// print array
	for (int i = 0; i < 10; i++) {
		std::cout << "array[" << i << "] "
			<< *array[i] << " says ";
			array[i]->makeSound();
	}

	// delete array
	for (int i = 0; i < 10; i++)
		delete array[i];
}

return 0;
}