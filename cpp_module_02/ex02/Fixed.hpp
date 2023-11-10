/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:57:33 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/10 08:05:33 by msoria-j         ###   ########.fr       */
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
		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);
		
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
};

std::ostream	&operator<<(std::ostream& os, Fixed const& element);

#endif /* FIXED_HPP */
