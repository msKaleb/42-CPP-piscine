/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:20:00 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/12 13:35:57 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>
#include "Point.hpp"
#include <cfloat> // for FLT_EPSILON macro

bool bsp( Point const a, Point const b, Point const c, Point const point);



int	main(void) {
	
	/* Point	p1((1.0f / 10.0f), (1.0f / 9.0f));
	Point	p2((100.0f / 8.0f), (100.0f / 3.0f));
	Point	p3((100.0f / 4.0f), (100.0f / 9.0f)); 
	float	x, y;
	x = p1.getX().toFloat() + (3.0f / 7.0f) * (p2.getX().toFloat() - p1.getX().toFloat());
	y = p1.getY().toFloat() + (3.0f / 7.0f) * (p2.getY().toFloat() - p1.getY().toFloat());
	Point	p4(x, y);*/
	
	Point	p1(0.0f, 0.0f);
	Point	p2(12.0f, 12.0f);
	Point	p3(14.0f, 0.0f);
	Point	p4(13.0f, 6.0f); // just on the midpoint
	
	std::cout << "Point p1 " << p1 \
			<< "Point p2 " << p2 \
			<< "Point p3 " << p3 \
			<< "Point p4 " << p4 << std::endl;
	
	std::cout << (bsp(p1, p2, p3, p4) ? "inside" : "outside") << std::endl;
	
	p4 = Point(13.0f, 5.99999975f); // this is the precision limit, closer to 6.0f ('y' midpoint), it fails
	
	std::cout << std::setfill('-') << std::setw(40)  << '\n';
	std::cout << "Point p1 " << p1 \
			<< "Point p2 " << p2 \
			<< "Point p3 " << p3 \
			<< "Point p4 " << p4 << std::endl;
			
	std::cout << (bsp(p1, p2, p3, p4) ? "inside" : "outside") << std::endl;
	return 0;
}
