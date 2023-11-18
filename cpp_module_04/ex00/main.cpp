/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:11:59 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/18 11:10:43 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int	main() {
	Animal	*meta = new Animal();
	Animal	*copy;
	Animal	a, b;

	copy = meta;
	a = b;
	
	std::cout << *meta << std::endl;
	std::cout << *copy << std::endl;
	
	meta->makeSound();
	delete meta;
	return 0;
}