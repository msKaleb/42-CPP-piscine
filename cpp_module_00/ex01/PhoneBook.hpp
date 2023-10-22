/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:25:54 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/22 22:46:07 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# define MAX_CONTACTS	3	// 8
# define OPT_ADD		"a"	// "ADD"
# define OPT_SEARCH		"s"	// "SEARCH"
# define OPT_EXIT		"e"	// "EXIT"

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"
# include "struct.h"

class PhoneBook {
	private:
		Contact	_phoneContacts[MAX_CONTACTS];
		int		_nContacts;
		int		_oldest;
		
		std::string	_truncateString(std::string);

	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact(t_data *td);
		void	showContact(int index);
		void	showContactInfo(int index);
		void	inputContactInfo(t_data *td);
		int		getNContacts();
};


#endif /* PHONE_BOOK_HPP */