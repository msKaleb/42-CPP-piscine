/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:48 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/20 15:20:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	Contact::_index += 1;
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact() {
	return ;
}

int	Contact::getIndex() {
	return (Contact::_index);
}

int	Contact::_index = 0;