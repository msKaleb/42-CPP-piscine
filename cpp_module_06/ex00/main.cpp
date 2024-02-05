#include "ScalarConverter.hpp"

/**
 * @todo remove -Wno-unused
  */
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "One parameter is needed" << std::endl;
		return 1;
	}
	std::string	str(argv[1]);
	ScalarConverter::convert(str);
	return (0);
}
