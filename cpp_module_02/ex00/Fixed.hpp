/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:57:33 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/04 14:42:52 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>



class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;

	public:

		Fixed();
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed	&operator=(Fixed const &assign);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif /* FIXED_HPP */