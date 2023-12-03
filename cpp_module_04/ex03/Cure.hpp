/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:38:32 by msoria-j          #+#    #+#             */
/*   Updated: 2023/12/03 15:18:57 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class	Cure : public AMateria
{
private:
	/* data */
public:
	/* Orthodox canonical */
	Cure();
	Cure(Cure const &copy);
	~Cure();
	Cure &operator=(const Cure &rhs);

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif /* CURE_HPP */
