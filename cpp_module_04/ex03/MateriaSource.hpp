/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:15 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 09:30:16 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

class	MateriaSource
{
private:
	/* data */

public:
	/* Orthodox canonical */
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &copy);
	MateriaSource &operator=(const MateriaSource &rhs);

};

#endif /* MATERIASOURCE_HPP */
