/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:20:00 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/11 21:28:34 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);



int	main(void) {

	Fixed	a(4.5f);
	Fixed	b(4);
	// Point	p(3.3f, 2.2f);
	Point	p1(0, 0);
	Point	p2(3.0f, 4.5f);
	Point	p3(3.2f, 0);
	Point	p4(1, 1);
	
	std::cout << "Fixed a: " << a << std::endl;
	std::cout << "Fixed b: " << b << std::endl;
	std::cout << "Point p1 " << p1 << std::endl;
	std::cout << "Point p2 " << p2 << std::endl;
	bsp(p1, p2, p3, p4);
	return 0;
}
