/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:17 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/21 06:09:18 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

class	Character
{
private:
	/* data */
public:
	/* Orthodox canonical */
	Character();
	Character(Character const &copy);
	~Character();
	Character &operator=(const Character &rhs);

};

#endif /* CHARACTER_HPP */
