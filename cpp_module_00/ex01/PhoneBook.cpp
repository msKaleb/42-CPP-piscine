/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:30 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/22 12:42:19 by msoria-j         ###   ########.fr       */
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

std::string	PhoneBook::_truncateString(std::string field) {

	if (field.length() <= 10)
		return (field);
	else
		return (field.substr(0, 9) + ".");
}

void	PhoneBook::showContact(int index) {
	std::cout << "|";
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << this->_truncateString(this->_phoneContacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << this->_truncateString(this->_phoneContacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << this->_truncateString(this->_phoneContacts[index].getNickName()) << "|"<< std::endl;
	return ;
}

void	PhoneBook::showContactInfo(int index) {
#include <iomanip>
	// std::cout << "Showing info of " << index << std::endl;
	std::cout << "\t" << std::setw(20) << "First name: ";
	std::cout << this->_phoneContacts[index].getFirstName() << std::endl;
	std::cout << "\t" << std::setw(20) << "Last name: ";
	std::cout << this->_phoneContacts[index].getLastName() << std::endl;
	std::cout << "\t" << std::setw(20) << "Nickname: ";
	std::cout << this->_phoneContacts[index].getNickName() << std::endl;
	std::cout << "\t" << std::setw(20) << "Phone number: ";
	std::cout << this->_phoneContacts[index].getPhoneNumber() << std::endl;
	std::cout << "\t" << std::setw(20) << "Darkest secret: ";
	std::cout << this->_phoneContacts[index].getDarkestSecret() << std::endl;
	return ;
}
