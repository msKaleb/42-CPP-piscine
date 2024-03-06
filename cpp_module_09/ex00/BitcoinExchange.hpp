#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "colors.h"
# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <map>

typedef std::map<std::string, float> myMap;
class	BitcoinExchange
{
private:
	/* data */
	BitcoinExchange();
	std::string const	_input;
	myMap				_date;

  // private methods, called after construction ********************************
	void	parseDate(const char* dateString) const;
	float	checkValue(const char* value) const;
	void	readCSV();
	void	readInput();
	void	trimString(std::string& str);

public:
  // exception classes *********************************************************
	class OutOfBounds : public std::exception {};
	class LargeNumber : public OutOfBounds {
		public: virtual const char* what() const throw() { return RED "Error: too large a number." RESET; }
	};
	class NegativeNumber : public OutOfBounds {
		public: virtual const char* what() const throw() { return RED "Error: not a positive number" RESET; }
	};
	class BadInput : public std::exception {
		public: virtual const char* what() const throw() { return RED "Error: bad input => " RESET; }
	};

	/* Orthodox canonical */
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	BitcoinExchange(std::string const& input);
};

#endif /* BITCOINEXCHANGE_HPP */
