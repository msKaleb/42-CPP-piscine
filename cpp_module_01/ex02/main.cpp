/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:39:21 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/30 09:01:00 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
								  
	std::cout << std::setw(20) << "str address: " << &str << std::endl;
	std::cout << std::setw(20) <<  "stringPTR address: " << stringPTR << std::endl;
	std::cout << std::setw(20) <<  "stringREF address: " << &stringREF << std::endl;
	
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
	std::cout << std::setfill(' ');
	
	std::cout << std::setw(20) << "str content: " << str << std::endl;
	std::cout << std::setw(20) <<  "stringPTR content: " << *stringPTR << std::endl;
	std::cout << std::setw(20) <<  "stringREF content: " << stringREF << std::endl;
	
	return (0);
}