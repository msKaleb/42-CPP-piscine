/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:16:56 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/11 21:32:49 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	/* ...... */
	// 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	float	ax, ay, bx, by, cx, cy;
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
	std::cout << "CA: " << CA << std::endl;

	return true;
}