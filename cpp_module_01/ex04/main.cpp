/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:17:35 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/31 18:46:51 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	replace(std::string *line, std::string s1, std::string s2) {
	size_t			found;
	
	found = line->find(s1);
	if (found != std::string::npos) {
		line->erase(found, s1.length());
		line->insert(found, s2);
		replace(line, s1, s2);
	}
}

int	main(int argc, char *argv[]) {
	std::string		infile, outfile, s1, s2, strTmp;
	std::ifstream	ifs;
	std::ofstream	ofs;
	
	if (argc != 4)
		return (1);

	infile = argv[1], s1 = argv[2], s2 = argv[3];
	outfile = infile + ".replace";
	ifs.open(infile.c_str());
	if (!ifs) {
		std::cout << "File \'" << infile << "\' not found!" << std::endl;
		ifs.close();
		return (1);
	}
	ofs.open(outfile.c_str());
	if (!ofs) {
		std::cout << "Couldn't write to file \'" << outfile << "\'" << std::endl;
		ofs.close();
		return (1);
	}
	
	if (ifs.peek() == EOF) // std::ifstream::traits_type::eof()
		std::cout << "File \'" << infile << "\' is empty!" << std::endl;
	for (std::string line; std::getline(ifs, line); ) {
		replace(&line, s1, s2);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
