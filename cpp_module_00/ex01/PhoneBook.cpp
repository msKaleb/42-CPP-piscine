/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:30 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/13 15:17:21 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	index = 0;
	std::cout << "Constructor, index: " << index << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}