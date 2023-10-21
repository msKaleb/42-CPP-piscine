/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:48 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/21 19:33:49 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	// Contact::_index += 1;
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact() {
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

/* int	Contact::getIndex() {
	return (Contact::_index);
} */

void	Contact::setContact(t_data *td) {
	this->_firstName = td->fn;
	this->_lastName = td->ln;
	this->_nickName = td->nn;
	this->_phoneNumber = td->pn;
	this->_darkestSecret = td->ds;
}

/* Getters */
std::string	Contact::getFirstName() {
	return (this->_firstName);
}

std::string	Contact::getLastName() {
	return (this->_lastName);
}

std::string	Contact::getNickName() {
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber() {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret() {
	return (this->_darkestSecret);
}

// int	Contact::_index = 0;