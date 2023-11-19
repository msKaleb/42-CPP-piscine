/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:18:45 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 17:32:51 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		/* Orthodox Canonical Form */
		Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &rhs);
		~Dog();

		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
};

#endif /* DOG_HPP */
