/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:57:37 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/09 18:38:58 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
	return ;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
	return ;
}

// From Int to fixed point:
// 	Just shift it the number of fractional bits to the left to skip the fractional part 
Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = (value << this->_fracBits);
	return ;
}

// From Float to fixed point:
// 	At first, we need the value of 1 in fixed-point format (1 << fracBits) - oneFp
// 	Then, we get the integer part and convert it to fixed-point
// 	Next, calculate the fractional part and multiply it with oneFp
// 	Add it to the integer part (rounded)
Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;

	int		oneFp = 1 << this->_fracBits; 			// constant to represent 1 in fixed-point format
	int		intPart = (int)value; 					// get the integer part of value
	float	fracPart = value - intPart; 			// get the fractional part of value
	
	this->_fixedPoint = intPart << this->_fracBits;	// integer part to fixed point
	this->_fixedPoint += roundf(oneFp * fracPart);	// fractional part to fixed point and add it to integer part

	// this->_fixedPoint = roundf(oneFp * value);	// all of the above can be done just with this line
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/	

Fixed	&Fixed::operator=(Fixed const &assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) {
		this->_fixedPoint = assign.getRawBits();
	}
	return *this;
}

std::ostream	&operator<<(std::ostream& os, Fixed const& element) {
	return (os << element.toFloat());
}

bool Fixed::operator>(Fixed const &rhs) {
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) {
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) {
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const {
	Fixed	ret(*this);
	
	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	Fixed	ret(*this);
	
	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	Fixed	ret(*this);
	int		oneFp = 1 << this->_fracBits;
	
	ret.setRawBits((this->getRawBits() * rhs.getRawBits()) / oneFp);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	Fixed	ret(*this);
	int		oneFp = 1 << this->_fracBits;
	double	a = (double)this->getRawBits();
	double	b = (double)rhs.getRawBits();
	
	ret.setRawBits((a / b) * oneFp);
	return (ret);
}


/*
** ------------------------------ MEMBER FUNCTIONS -----------------------------
*/	

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

// The reverse of int to fixed-point:
// 	Instead of bitshifting to the left, bitshift it to the right
int		Fixed::toInt(void) const {
	return ((int)this->_fixedPoint >> this->_fracBits);
}

// The reverse of float to fixed-point:
// 	Instead of multiplying value with oneFp (1 << fracBits),
// 	divide the stored fixed-point number by oneFp 
float	Fixed::toFloat(void) const {
	int		oneFp = 1 << this->_fracBits;
	return ((float)this->_fixedPoint / oneFp);
}
