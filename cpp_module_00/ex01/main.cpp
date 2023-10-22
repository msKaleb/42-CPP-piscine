/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:01:19 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/22 12:44:01 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "struct.h"

void	displaySearchingHeader(void) {
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
}

void	inputContactInfo(t_data *td) {
	std::cout << "First name: ";
	std::getline(std::cin, td->fn);
	std::cout << "Last name: ";
	std::getline(std::cin, td->ln);
	std::cout << "Nickname: ";
	std::getline(std::cin, td->nn);
	std::cout << "Phone number: ";
	std::getline(std::cin, td->pn);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, td->ds);
	std::cout << std::endl;
}

int	main(void)
{
	PhoneBook	pb;
	std::string	opt;
	int			run = 1;
	int			searchIndex;
	t_data		td;
	
	/* debugging */
		td.fn = "Mikel";
		td.ln = "Soria";
		td.nn = "msoria-j";
		td.pn = "680752260";
		td.ds = "nothing";
		pb.addContact(&td);

		td.fn = "un_nombre_muy_largo";
		td.ln = "un_apellido_muy_largo";
		td.nn = "un_nickname_muy_largo";
		td.pn = "(+34)680752260";
		td.ds = "un secreto que flipas";
		pb.addContact(&td);
		
	/* debugging */

	while (run)
	{
		opt.clear();
		std::cout << "Enter an option: ";
		std::getline(std::cin, opt);
		if (opt == "a")
		{
			inputContactInfo(&td);
			pb.addContact(&td);
			std::cout << "number of contacts: " << pb.getNContacts() << std::endl;
		}
		else if (opt == "s")
		{
			displaySearchingHeader();			
			for (int i = 0; i < pb.getNContacts(); i++)
				pb.showContact(i);
			std::cout << "Enter index: ";
			std::getline(std::cin, opt);
			searchIndex = std::atoi(opt.c_str());
			if (searchIndex <= 0 || searchIndex > pb.getNContacts())
				std::cout << "Bad index" << std::endl;
			else
				pb.showContactInfo(searchIndex - 1);
		}
		else if (opt == "e")
			run = 0;
	}
}
