#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <map>

class	BitcoinExchange
{
private:
	/* data */
	BitcoinExchange();
	std::string const				_input;
	std::map<std::string, float>	_date;

	time_t	parseDate(const char* dateString) const;
	void	readCSV();
	void	readInput();
	void	trimString(std::string& str);
	

public:
	/* Orthodox canonical */
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	BitcoinExchange(std::string const& input);
};

#endif /* BITCOINEXCHANGE_HPP */
