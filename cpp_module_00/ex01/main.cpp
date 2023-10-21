/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:01:19 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/21 19:25:22 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include "struct.h"

int	main(void)
{
	PhoneBook	pb;
	std::string	opt;
	int			run = 1;
	t_data		td;
	
	while (run)
	{
		std::cout << "Enter an option: ";
		// system("clear");
		std::getline(std::cin, opt);
		// std::cout << opt << std::endl;
		if (opt == "a")
		{
			std::cout << "First name: ";
			std::getline(std::cin, td.fn);
			std::cout << "Last name: ";
			std::getline(std::cin, td.ln);
			std::cout << "Nickname: ";
			std::getline(std::cin, td.nn);
			std::cout << "Phone number: ";
			std::getline(std::cin, td.pn);
			std::cout << "Darkest secret: ";
			std::getline(std::cin, td.ds);
			std::cout << std::endl;
			
			pb.addContact(&td);
			std::cout << "number of contacts: " << pb.getNContacts() << std::endl;
		}
		else if (opt == "s")
		{
			std::cout << "|";
			std::cout << std::setw(10) << "Index" << "|";
			std::cout << std::setw(10) << "First name" << "|";
			std::cout << std::setw(10) << "Last name" << "|";
			std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
			
			for (int i = 0; i < pb.getNContacts(); i++)
			{
				pb.showContact(i);
			}
				
				
		}
		else if (opt == "e")
			run = 0;
	}
}
