/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:30 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/23 16:35:26 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	// std::cout << "PB Constructor called" << std::endl;
	this->_nContacts = 0;
	this->_oldest = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "PB destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(t_data *td) {

	if (this->_nContacts >= MAX_CONTACTS)
	{
		std::cout << "Max contacts reached. Replacing the oldest one..." << std::endl;
		this->_phoneContacts[this->_oldest].setContact(td);
		this->_oldest++;
		if (this->_oldest == MAX_CONTACTS)
			this->_oldest = 0;
	}
	else
	{
		this->_phoneContacts[this->_nContacts].setContact(td);
		if (this->_nContacts <= MAX_CONTACTS)	
			this->_nContacts++;
	}
}

int	PhoneBook::getNContacts() const {
	return (this->_nContacts);
}

bool	PhoneBook::isValidField(std::string field) const
{
	std::string whitespaces (" \t\f\v\n\r");
	
	if (field.empty())
		return (false);
	if (field.find_last_not_of(whitespaces) == std::string::npos)
		return (false);
	return (true);
}

bool	PhoneBook::isValidPhoneNumber(std::string phoneNumber) const
{
	std::string	numbers ("0123456789- ");
	
	if (phoneNumber.empty())
		return (false);
	if (phoneNumber.find_last_not_of(numbers) != std::string::npos)
		return (false);
	if (phoneNumber.find_first_not_of(' ') == std::string::npos)
		return (false);
	if (phoneNumber.find_first_not_of('-') == std::string::npos)
		return (false);
	return (true);
}

void	PhoneBook::inputContactInfo(t_data *td) {
	std::cout << BLUE << "Adding contact (no field can be empty)..." << std::endl << RESET;
	do {
		std::cout << "First name: ";
		std::getline(std::cin, td->fn);
	} while (!this->isValidField(td->fn));
	do {
		std::cout << "Last name: ";
		std::getline(std::cin, td->ln);
	} while (!this->isValidField(td->ln));		
	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, td->nn);
	} while (!this->isValidField(td->nn));	
	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, td->pn);
	} while (!this->isValidPhoneNumber(td->pn));
	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, td->ds);
	} while (!this->isValidField(td->ds));		
		
	std::cout << std::endl;
	return ;
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
