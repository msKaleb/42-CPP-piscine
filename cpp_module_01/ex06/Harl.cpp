/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:34:32 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/01 12:55:34 by msoria-j         ###   ########.fr       */
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
	std::string	levels[] = {
		std::string("DEBUG"), 
		std::string("INFO"), 
		std::string("WARNING"), 
		std::string("ERROR")
		};

	void		(Harl::*funct[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
		};

	size_t indexLevel;
	for (indexLevel = 0; indexLevel < (sizeof(levels) / sizeof(*levels)); indexLevel++) {
		if (level == levels[indexLevel]) {
			break ;
		}
	}

	enum	e_levels {DEBUG, INFO, WARNING, ERROR};
	// '__attribute__ ((fallthrough))': used to go through different cases without a 'break;'
	switch (indexLevel)
	{
	case DEBUG:
		std::cout << GREEN << "[ DEBUG ]" << std::endl << RESET;
		(this->*funct[DEBUG])();
		__attribute__ ((fallthrough));
	case INFO:
		std::cout << GREEN  << "[ INFO ]" << std::endl << RESET;
		(this->*funct[INFO])();
		__attribute__ ((fallthrough));
	case WARNING:
		std::cout << GREEN  << "[ WARNING ]" << std::endl << RESET;
		(this->*funct[WARNING])();
		__attribute__ ((fallthrough));
	case ERROR:
		std::cout << GREEN  << "[ ERROR ]" << std::endl << RESET;
		(this->*funct[ERROR])();
		break;
	
	default:
		std::cout << RED << level <<" is not a valid level" << std::endl << RESET;
		break;
	}
}
