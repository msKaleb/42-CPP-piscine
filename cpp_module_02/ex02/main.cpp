/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:47:23 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/09 18:39:16 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>

int	main(void) {

	Fixed	a;
/* 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl; */

	Fixed	b;
	
	b = Fixed(4.5f);
	a = Fixed(2.5f);
	Fixed c(Fixed(5.05f) * Fixed(2));
	Fixed	d = b / a;
	std::cout << c << std::endl;
	if (a < b)
		std::cout << "true" << std::endl;
	
	return 0;
}
