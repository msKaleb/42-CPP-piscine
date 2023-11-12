/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:16:56 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/12 12:31:15 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
} */

/**
 * Barycentric coordinate system:
 *  x = a * x1 + b * x2  + c * x3
 *	y = a * y1 + b * y2 + c * y3
 *	a + b + c = 1
 *
 *  a = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3))
 *  b = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3))
 *  c = 1 - a - b
 * 
 *  point lies in T (triangle) if 0 <= a <= 1 and 0 <= b <= 1 and 0 <= c <= 1
 * */
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float	denominator;
	float	sA, sB, sC; // scalars a, b, c
	
	if (point == a || point == b || point == c)
		return(std::cout << "equals: ", false);
	
	denominator = ((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat())
		+ (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));

	sA = ((b.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat())
		+ (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat()));
	sA /= denominator;

	sB = ((c.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat())
		+ (a.getX().toFloat() - c.getX().toFloat()) * point.getY().toFloat() - c.getY().toFloat());
	sB /= denominator;
	
	sC = 1 - sA - sB;

	std::cout << "sA: " << sA << " sB: " << sB << " sC: " << sC << " " << std::endl;
	return (0 < sA && sA < 1 && 0 < sB && sB < 1 && 0 < sC && sC < 1);

	return true;
}

// Some previous tests
	/* ...... */
	// 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	/* float	ax, ay, bx, by, cx, cy;
	(void)point;

	ax = a.getX().toFloat();
	ay = a.getY().toFloat();
	bx = b.getX().toFloat();
	by = b.getY().toFloat();
	cx = c.getX().toFloat();
	cy = c.getY().toFloat();
	
	double	area = 0.5 * fabs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    double	AB = calculateDistance(ax, ay, bx, by);
    double	BC = calculateDistance(bx, by, cx, cy);
    double	CA = calculateDistance(cx, cy, ax, ay);
	
	std::cout << "area: " << area << std::endl;
	std::cout << "AB: " << AB << std::endl;
	std::cout << "BC: " << BC << std::endl; 
	std::cout << "CA: " << CA << std::endl;*/
	