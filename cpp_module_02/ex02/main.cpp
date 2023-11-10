/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:47:23 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/10 18:28:26 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>
#include <cfloat>

int	main(void) {

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		return 0;
	}
	{
		
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
		// a = Fixed(FLT_EPSILON);
		a = Fixed(5.1f);
		Fixed c(Fixed(5.05f) * Fixed(2));
		Fixed	d = b / a;
		
		/* int i = 0;
		std::cout << "i before incrementing " << i << std::endl;
		while (i++ <= 5)
			std::cout << "i after " << i << std::endl;

		std::cout << "i before decrementing " << i << std::endl;
		while (i-- >= 0)
			std::cout << "i after " << i << std::endl; */
			
		/* std::cout << "a before incrementing " << a << std::endl;
		while (++a <= 1)
			std::cout << "a after " << a << std::endl;

		std::cout << "a before decrementing " << a << std::endl;
		while (--a >= 0)
			std::cout << "a after " << a << std::endl; */
			
		if (a > b)
			std::cout << "true" << std::endl;
		
		std::cout << "max: " << Fixed::max( a, b ) << std::endl;
		std::cout << "min: " << Fixed::min( a, b ) << std::endl;
		
		return 0;
	}
}
