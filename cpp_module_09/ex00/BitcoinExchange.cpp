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

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _input(copy._input), _date(copy._date) {
	// std::cout << "BitcoinExchange: Copy Constructor Called" << std::endl;
	/* if (this != &copy)
		*this = copy; */
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	// std::cout << "BitcoinExchange: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->~BitcoinExchange();
		new(this) BitcoinExchange(rhs);
	}
	return (*this);
}

// parametrized constructor ****************************************************
BitcoinExchange::BitcoinExchange(std::string const& input) : _input(input) {}

// trim strings ****************************************************************
void	BitcoinExchange::trimString(std::string& str) {
	std::string		whiteSpaces = " \f\n\r\t\v";

	str.erase(0, str.find_first_not_of(whiteSpaces));
	str.erase(str.find_last_not_of(whiteSpaces) + 1);
	return ;
}

// check if the value is out of bounds *****************************************
float	BitcoinExchange::checkValue(const char* value) const {
	char*	ending ;
	float	fValue = std::strtof(value, &ending);

	if (*ending != 0)
		throw BadInput();
	if (fValue > 1000.0f)
		throw LargeNumber();
	else if (fValue < 0.0f)
		throw NegativeNumber();
	return fValue;
}

// search the input date in the map container **********************************
float	BitcoinExchange::getExchangeRate(std::string const& inputDate, 
									std::string const& value) {
	float	fValue = checkValue(value.c_str());
	float	product = 0.0f;

	if (_date.find(inputDate) != _date.end())
		product = _date[inputDate] * fValue;
	else {
		myMap::iterator	it;
		// get first element greater or equal than inputDate
		it = _date.lower_bound(inputDate);
		--it; // go one step backward
		// it->first => key | it->second => value
		product = it->second * fValue;
	}
	return product;
}

// read the input file passed as parameter *************************************
void	BitcoinExchange::readInput() {
	std::fstream	fin;
	std::string		row, inputDate, value;
	std::string		whiteSpaces = " \f\n\r\t\v";
	float			product = 0.0f;

	fin.open(_input.c_str(), std::ios::in);
	if (!fin) {
		std::cerr << "Couldn't open " << _input << std::endl;
		return ;
	}
	
	while (!fin.eof()) {
		std::getline(fin, row);

		inputDate = row.substr(0, row.find_first_of("|"));
		value = row.substr(row.find_first_of("|") + 1);
		trimString(inputDate);
		trimString(value);

		// 1,2 -> 1.2, etc
		if (value.find(',') != value.npos)
			value.replace(value.find(','), 1, ".");

		// skip <date | value> and empty lines
		if ((inputDate == "date" && value == "value")
			|| (inputDate.find_first_not_of(whiteSpaces) == std::string::npos))
			continue ;

		try {
			parseDate(inputDate.c_str());
			if (inputDate.empty() || value.empty())
				throw BadInput();
			product = getExchangeRate(inputDate, value);
			std::cout << inputDate << " => " << value << " = " << product << std::endl;
		} catch (BadInput& e) {
			std::cout << e.what() << row << std::endl;
		} catch (OutOfBounds& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

// discard lines without date ***********************************************
void	BitcoinExchange::parseDate(const char* dateString) const {
	struct tm	tmStruct;

	// initialize all fields to 0
	std::memset(&tmStruct, 0, sizeof(struct tm));
	if (strptime(dateString, "%Y-%m-%d", &tmStruct) == NULL)
		throw BadInput();
	if (mktime(&tmStruct) == -1)
		throw BadInput();
}

// read the database and store it into a map container **********************
void	BitcoinExchange::readCSV() {
	std::fstream		fin;
	std::string			row, key, value;

	fin.open("./data.csv", std::ios::in);
	if (!fin) {
		std::cerr << "Couldn't open [data.csv] file" << std::endl;
		throw std::exception();
	}

	while (!fin.eof()) {
		std::getline(fin, row);
		std::stringstream	tmpRow(row);
		std::getline(tmpRow, key, ',');
		std::getline(tmpRow, value, ',');
		try {
			parseDate(key.c_str());
			_date[key] = std::strtof(value.c_str(), NULL);
		} catch (BadInput& e) {
			continue ; // don't show BadInput messages on database load
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	// close the file
	fin.close();
}

// loop over to check *********************************************************
void	BitcoinExchange::printMap() {
	myMap::iterator	it = _date.begin();
	myMap::iterator	ite = _date.end();
	while (it != ite) {
		std::cout << "key: " << it->first << " | value: " << it->second << std::endl;
		it++;
	}

}
