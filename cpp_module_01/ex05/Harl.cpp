/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:34:32 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/06 08:48:56 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-"
		<< "triple-pickle-special-ketchup burger. \nI really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger!\nIf you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working "
		<< "here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complaint(std::string level) {
	// levels array
	std::string	levels[] = {
		std::string("DEBUG"), 
		std::string("INFO"), 
		std::string("WARNING"), 
		std::string("ERROR")
		};

	// pointer to functions array
	void	(Harl::*funct[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
		};

	for (size_t i = 0; i < (sizeof(levels) / sizeof(*levels)); i++) {
		if (level == levels[i]) {
			std::cout  << GREEN << levels[i] << " level:" << std::endl << RESET;
			// (*this.*funct[i])(); // also works
			(this->*funct[i])();
			return ;
		}
	}
	std::cout << RED << level <<" is not a valid level" << std::endl << RESET;
}
