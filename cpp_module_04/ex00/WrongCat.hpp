/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:07:09 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/19 13:08:14 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	/* Orthodox Canonical Form */
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat	&operator=(const WrongCat &rhs);
	~WrongCat();

	void	makeSound(void) const;
};

#endif /* WRONG_CAT_HPP */
