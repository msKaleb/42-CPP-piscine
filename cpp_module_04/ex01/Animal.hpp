/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:26:14 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 17:34:27 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;
		Animal(std::string const &type);

	public:
		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal			&operator=( Animal const & rhs );
		std::string		getType(void) const;
		virtual void	makeSound(void) const;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ANIMAL_HPP*/