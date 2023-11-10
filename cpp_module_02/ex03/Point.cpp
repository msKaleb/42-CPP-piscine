/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:20:11 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/10 19:20:13 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point &src) {
	this->operator=(src);
}


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
		this->getX().operator=(rhs.getX());
		this->getY().operator=(rhs.getY());
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Point const &i)
{
	//o << "Value = " << i.getValue();
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