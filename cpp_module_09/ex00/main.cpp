#include "BitcoinExchange.hpp"

/**
 * @todo orthodox canonical
  */
int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;

	std::string		input(argv[1]);
	BitcoinExchange	be(input);

	try {
		// load database into a map container
		be.readCSV();
		// input file to calculate the exchange rate
		be.readInput();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	BitcoinExchange	copy = be;
	// copy.printMap();
	return (0);
}
