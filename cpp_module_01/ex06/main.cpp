/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:28:35 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/01 12:52:27 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[]) {
	Harl	complainingHarl;
	
	if (argc != 2) {
		std::cout << RED << "Bad argument number. Defining default level as DEBUG... "
			<< std::endl << RESET;
		complainingHarl.complaint("DEBUG");
	}
	else
		complainingHarl.complaint(argv[1]);
	return (0);
}
