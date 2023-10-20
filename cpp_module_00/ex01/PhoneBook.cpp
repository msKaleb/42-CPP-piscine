/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:30 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/20 17:07:25 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PB Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::AddContact() {
	// this->_contacts[newContact.getIndex()] = newContact;
	Contact	newContact;

	if (newContact.getIndex() > 2)
		std::cout << "ep, fallo" << std::endl;
}
