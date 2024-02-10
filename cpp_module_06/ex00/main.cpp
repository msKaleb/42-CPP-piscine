#include "ScalarConverter.hpp"

/**
 * @todo remove -Wno-unused
 * @todo print *.00 for double and float in int and char constructor
  */
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "One parameter is needed" << std::endl;
		std::cout << MAX_INT << std::endl;
		return 1;
	}
	std::string	str(argv[1]);

	ScalarConverter::convert(str);
	return (0);
}
