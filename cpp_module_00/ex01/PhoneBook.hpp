/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:25:54 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/20 15:19:28 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
private:
	/* data */
	// Contact	_contacts[8];
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void	AddContact();
};


#endif /* PHONE_BOOK_HPP */