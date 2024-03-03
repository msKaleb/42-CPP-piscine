#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <map>

class	BitcoinExchange
{
private:
	/* data */
	std::string const	_input;

	void	readCSV() const;
	time_t	parseDate(const char* dateString) const;

public:
	/* Orthodox canonical */
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	BitcoinExchange(std::string const& input);
};

#endif /* BITCOINEXCHANGE_HPP */
