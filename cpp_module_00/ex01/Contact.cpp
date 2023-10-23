/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:48 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:22 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	// std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact() {
	// std::cout << "Contact destructor called" << std::endl;
	return ;
}

void	Contact::setContact(t_data *td) {
	this->_firstName = td->fn;
	this->_lastName = td->ln;
	this->_nickName = td->nn;
	this->_phoneNumber = td->pn;
	this->_darkestSecret = td->ds;
}

/* Getters */
std::string	Contact::getFirstName() const {
	return (this->_firstName);
}

std::string	Contact::getLastName() const {
	return (this->_lastName);
}

std::string	Contact::getNickName() const {
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber() const {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret() const {
	return (this->_darkestSecret);
}
