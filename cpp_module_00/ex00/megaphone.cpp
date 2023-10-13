/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:17:13 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/13 13:11:35 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	std::string	str = "";

	for (int i = 1; i < argc; i++)
		str.append(argv[i]);
		
	int	len = str.length();
	
	for (int i = 0; i < len ; i++)
		str[i] = toupper(str[i]);
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << str << std::endl;
	return (0);
}
