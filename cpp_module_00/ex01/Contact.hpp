/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:23 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/20 15:22:45 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	static int	_index;			// non-member attribute
public:
	Contact();
	~Contact();

	bool	setFirstName(std::string firstName);
	bool	setLastName(std::string lastName);
	bool	setNickName(std::string NickName);

	static int	getIndex();
};

#endif /* CONTACT_HPP */