/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:54:08 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 12:57:09 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
		WrongAnimal(std::string const &type);

	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal		&operator=( WrongAnimal const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* WRONG_ANIMAL_HPP*/