/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:19:50 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/10 19:19:52 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		static const int	_fracBits = 8;
		int					_fixedPoint;

	public:

		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed	&operator=(Fixed const &assign);
		
		// comparison operators overload (rhs = right hand side)
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		
		// arithmetic operators overload
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		
		// increment - decrement operators overload
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&min(Fixed &a, Fixed &b);
		
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
};
std::ostream	&operator<<(std::ostream& os, Fixed const& element);

#endif /* FIXED_HPP */
