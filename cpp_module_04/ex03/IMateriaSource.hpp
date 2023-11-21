/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:27:56 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 09:29:43 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class	IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif /* IMATERIASOURCE_HPP */
