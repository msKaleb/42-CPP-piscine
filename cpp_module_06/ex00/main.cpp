#include "ScalarConverter.hpp"

/**
 * @todo remove -Wno-unused
 * @todo 123322.131 (6 digits) gives 123322f and 123322 in float and double, why?
 * @todo nan(f), inf(f), etc.
  */
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "One parameter is needed" << std::endl;
		// info for debugging
		// std::cout << "Max int:    " << MAX_INT << std::endl;
		// std::cout << "Max float:  " << MAX_FLOAT << std::endl;
		// std::cout << "Max double: " << MAX_DOUBLE << std::endl;
		// std::cout << "Min int:    " << MIN_INT << std::endl;
		// std::cout << "Min float:  " << MIN_FLOAT << std::endl;
		// std::cout << "Min double: " << MIN_DOUBLE << std::endl;
		return 1;
	}
	std::string	str(argv[1]);
	ScalarConverter::convert(str);
	return (0);
}
