#include "BitcoinExchange.hpp"

/**
 * @todo remove Wno-unused
  */
int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	std::string		input(argv[1]);

	BitcoinExchange	be(input);


	return (0);
}
