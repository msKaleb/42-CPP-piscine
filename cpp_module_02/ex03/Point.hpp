/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:45:48 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/12 11:29:54 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		~Point();

		Point	&operator=(Point const &rhs);

		bool	operator==(Point const &rhs) const;

		Fixed	getX() const;
		Fixed	getY() const;

	private:

		Fixed const	_x;
		Fixed const	_y;

};

std::ostream	&operator<<(std::ostream& o, Point const& i);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */