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

void	BitcoinExchange::trimString(std::string& str) {
	std::string		whiteSpaces = " \f\n\r\t\v";

	str.erase(0, str.find_first_not_of(whiteSpaces));
	str.erase(str.find_last_not_of(whiteSpaces) + 1);
}
void	BitcoinExchange::readInput() {
	float			fValue = 0.0f, product = 0.0f;
	std::fstream	fin;
	std::string		row, inputDate, value;
	std::string		whiteSpaces = " \f\n\r\t\v";

	fin.open(_input.c_str(), std::ios::in);
	if (!fin)
		std::cout << "Couldn't open " << _input << std::endl;
	
	while (!fin.eof()) {
		std::getline(fin, row);

		/* std::stringstream	tmpRow(row); // move it out of loop?
		std::getline(tmpRow, inputDate, '|');
		std::getline(tmpRow, value, '|'); */
		inputDate = row.substr(0, row.find_first_of("|"));
		value = row.substr(row.find_first_of("|") + 1);
		trimString(inputDate);
		trimString(value);
		fValue = std::strtof(value.c_str(), NULL);
		// if the line contains only whitespaces, do nothing, skip <date | value> line
		if (inputDate == "date" || inputDate.find_first_not_of(whiteSpaces) == std::string::npos)
			continue ;

		// todo: ignore newlines, add bad input for inexistent dates, etc
		if (this->parseDate(inputDate.c_str()) == -1)
			std::cout << "Error: bad input => " << row << std::endl; // throw exception?
		else if (fValue < 0 || fValue > 1000)
			std::cout << "Error: too large a number." << std::endl; // throw exception?
		else {
			
			product = _date[inputDate] * fValue;
			std::cout << inputDate << " => " << value << " = " << (product * fValue) /* get product from map */ << std::endl;
		}
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