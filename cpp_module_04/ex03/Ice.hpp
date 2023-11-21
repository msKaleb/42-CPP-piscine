/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:42:19 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 12:13:33 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class	Ice : public AMateria
{
private:
	/* data */

public:
	/* Orthodox canonical */
	Ice ();
	Ice (Ice const &obj);
	~Ice ();
	Ice &operator= (const Ice &obj);

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif /* ICE_HPP */
