/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:18:45 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 13:05:59 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
	
	public:
		/* Orthodox Canonical Form */
		Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &rhs);
		~Dog();

		virtual void	makeSound(void) const;
};

#endif /* DOG_HPP */
