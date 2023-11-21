/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:15 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 15:06:38 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class AMateria;

class	MateriaSource : public IMateriaSource
{
private:
	/* data */
	AMateria	**_sources;
	int			_sourceCounter;

public:
	/* Orthodox canonical */
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &copy);
	MateriaSource &operator=(const MateriaSource &rhs);

	virtual void		learnMateria(AMateria*);
	virtual AMateria	*createMateria(std::string const &type);
};

#endif /* MATERIASOURCE_HPP */
