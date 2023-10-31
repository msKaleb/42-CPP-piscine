/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:17:35 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/31 15:51:17 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char *argv[]) {
	std::string		infile, outfile, s1, s2, strTmp;
	std::ifstream	ifs;
	std::ofstream	ofs;
	size_t			found;
	
	if (argc != 4)
		return (1);

	infile = argv[1], s1 = argv[2], s2 = argv[3];
	outfile = infile + ".replace";
	ifs.open(infile.c_str());
	ofs.open(outfile.c_str());
	
	for (std::string line; std::getline(ifs, line); ) {
		found = line.find(s1);
		if (found != std::string::npos) {
			line.erase(found, s1.length());
			line.insert(found, s2);
		}
		std::cout << line << std::endl;
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}