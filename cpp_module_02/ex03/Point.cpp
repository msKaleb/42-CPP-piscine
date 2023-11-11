/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:20:11 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/11 20:29:07 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point	&Point::operator=(Point const &rhs)
{
	if ( this != &rhs ) {
		// this->getX().operator=(rhs.getX());
		// this->getY().operator=(rhs.getY());
		this->~Point();
		new(this) Point(rhs);
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Point const &i)
{
	o << "x: " << i.getX() << " y: " << i.getY() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}

/* ************************************************************************** */