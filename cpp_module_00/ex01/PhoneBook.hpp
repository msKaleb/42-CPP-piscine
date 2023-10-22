/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:25:54 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/22 11:58:45 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# define MAX_CONTACTS 2

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"
# include "struct.h"

class PhoneBook {
	private:
		/* data */
		Contact	_phoneContacts[MAX_CONTACTS];
		int		_nContacts;

	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact(t_data *td);
		void	showContact(int index);
		void	showContactInfo(int index);
		int		getNContacts();
};


#endif /* PHONE_BOOK_HPP */