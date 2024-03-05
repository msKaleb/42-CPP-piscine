#include "BitcoinExchange.hpp"

// *****************************************************************************
// orthodox canonical
// *****************************************************************************
BitcoinExchange::BitcoinExchange() {
	// std::cout << "BitcoinExchange: Default Constructor Called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "BitcoinExchange: Destructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	// std::cout << "BitcoinExchange: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	// std::cout << "BitcoinExchange: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

// parametrized constructor ****************************************************
BitcoinExchange::BitcoinExchange(std::string const& input) : _input(input) {
	this->readCSV();
	this->readInput();
}

void	BitcoinExchange::readInput() {
	std::fstream	fin;
	std::string		row, date, value;

	fin.open(_input.c_str(), std::ios::in);
	if (!fin)
		std::cout << "Couldn't open " << _input << std::endl;
	
	while (!fin.eof()) {
		std::getline(fin, row);

		std::stringstream	tmpRow(row);
		std::getline(tmpRow, date, '|');
		std::getline(tmpRow, value, '|');

		// todo: ignore newlines, add bad input for inexistent dates, etc
		if (this->parseDate(date.c_str()) != -1)
			std::cout << date << std::endl;
		else
			std::cout << "not a date" << std::endl;
	}
}

// discard lines without date ***********************************************
time_t	BitcoinExchange::parseDate(const char* dateString) const {
	struct tm	tmStruct;

	if (strptime(dateString, "%Y-%m-%d", &tmStruct) == NULL)
		return -1;
	return mktime(&tmStruct);
}

// read the database and store it into a map container **********************
void	BitcoinExchange::readCSV() {
	// std::map<std::string, float>	date;

	std::fstream		fin;
	std::string			row, key, value;

	fin.open("./data.csv", std::ios::in);
	if (!fin)
		std::cout << "Couldn't open [data.csv] file" << std::endl;

	while (!fin.eof()) {
		std::getline(fin, row);
		std::stringstream	tmpRow(row);
		std::getline(tmpRow, key, ',');
		std::getline(tmpRow, value, ',');
		if (parseDate(key.c_str()) != -1)
			_date[key] = std::strtof(value.c_str(), NULL);
	}
 // loop over to check *********************************************************
	/* std::map<std::string, float>::iterator	it = _date.begin();
	std::map<std::string, float>::iterator	ite = _date.end();
	while (it != ite) {
		std::cout << "key: " << it->first << " | value: " << it->second << std::endl;
		it++;
	} */

	// close the file
	fin.close();
}