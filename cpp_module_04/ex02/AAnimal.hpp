/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:26:14 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/20 08:49:32 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string	_type;
		AAnimal(std::string const &type);

	public:
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal			&operator=( AAnimal const & rhs );
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ANIMAL_HPP*/