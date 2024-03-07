#include "BitcoinExchange.hpp"

/**
 * @todo orthodox canonical
  */
int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;

	std::string		input(argv[1]);
	BitcoinExchange	be(input);

	// load database into a map container
	be.readCSV();
	// input file to calculate the exchange rate
	be.readInput();

	BitcoinExchange	copy = be;
	copy.printMap();
	return (0);
}
