/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:25:04 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 13:05:52 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	/* Orthodox Canonical Form */
	Cat();
	Cat(const Cat &src);
	Cat	&operator=(const Cat &rhs);
	~Cat();

	virtual void	makeSound(void) const;
};

#endif /* CAT_HPP */
