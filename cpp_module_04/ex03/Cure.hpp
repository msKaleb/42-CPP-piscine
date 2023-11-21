/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:38:32 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 05:38:33 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

class	Cure
{
private:
	/* data */
public:
	/* Orthodox canonical */
	Cure();
	Cure(Cure const &copy);
	~Cure();
	Cure &operator=(const Cure &rhs);

};

#endif /* CURE_HPP */
