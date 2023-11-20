/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:20:00 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/20 22:54:52 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria // Abstract class
{
protected:
	/* data */
	std::string const	_type;

public:
	/* Orthodox canonical */
	AMateria(/* args */);
	AMateria(AMateria const &copy);
	AMateria &operator=(AMateria const &rhs);
	virtual ~AMateria();

	// parametrized constructor
	AMateria(std::string const &type);

	std::string const	&getType() const;			// returns the materia type
	virtual AMateria	*clone() const = 0;			// pure virtual, to be implemented
	virtual void		use(ICharacter &target);	// to be overridden
};

#endif /* AMATERIA_HPP */
