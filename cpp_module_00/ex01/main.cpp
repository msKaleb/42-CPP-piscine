/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:01:19 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/23 15:46:01 by msoria-j         ###   ########.fr       */
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

int	main(void)
{
	PhoneBook	pb;
	std::string	opt;
	int			run = 1;
	int			searchIndex;
	t_data		td;
	
	/* debugging */
		/* td.fn = "Mikel";
		td.ln = "Soria";
		td.nn = "msoria-j";
		td.pn = "666888777";
		td.ds = "nothing";
		pb.addContact(&td);

		td.fn = "un_nombre_muy_largo";
		td.ln = "un_apellido_muy_largo";
		td.nn = "un_nickname_muy_largo";
		td.pn = "(+34)666888777";
		td.ds = "un secreto muy largo";
		pb.addContact(&td); */
	/* debugging */

	while (run)
	{
		opt.clear();
		std::cout << YELLOW << "Enter an option: " << RESET;
		std::getline(std::cin, opt);
		if (opt == OPT_ADD)
		{
			pb.inputContactInfo(&td);
			pb.addContact(&td);
			std::cout << "number of contacts: " << pb.getNContacts() << std::endl;
		}
		else if (opt == OPT_SEARCH)
		{
			displaySearchingHeader();			
			for (int i = 0; i < pb.getNContacts(); i++)
				pb.showContact(i);
			std::cout << GREEN << "Enter index: " << RESET;
			std::getline(std::cin, opt);
			searchIndex = std::atoi(opt.c_str());
			if (searchIndex <= 0 || searchIndex > pb.getNContacts())
				std::cout << RED << "Please enter a valid index" << std::endl << RESET;
			else
				pb.showContactInfo(searchIndex - 1);
		}
		else if (opt == OPT_EXIT)
			run = 0;
	}
}
