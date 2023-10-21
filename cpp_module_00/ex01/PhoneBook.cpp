/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:30 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/21 19:27:19 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PB Constructor called" << std::endl;
	this->_nContacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PB destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(t_data *td) {

	if (this->_nContacts >= MAX_CONTACTS) // max contacts to be 8
	{
		std::cout << "ep, fallo" << std::endl; // change, erase oldest one
		this->_nContacts = 0;
		return ;
	}
	this->_phoneContacts[this->_nContacts].setContact(td);
	this->_nContacts++;
}

int	PhoneBook::getNContacts() {
	return (this->_nContacts);
}

void	PhoneBook::showContact(int index) {
	std::cout << "|";
	std::cout << std::setw(10) << this->_phoneContacts[index].getFirstName() << "|";
	std::cout << std::setw(10) << this->_phoneContacts[index].getFirstName() << "|";
	std::cout << std::setw(10) << this->_phoneContacts[index].getFirstName() << "|";
	std::cout << std::setw(10) << this->_phoneContacts[index].getFirstName() << "|";
	std::cout << std::setw(10) << this->_phoneContacts[index].getFirstName() << "|";
}