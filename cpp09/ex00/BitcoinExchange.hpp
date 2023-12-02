
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange {
private:
	std::map<std::string,int> _exchangeRates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);
	
};

int exchanging(char *input);

#endif // BITCOINEXCHANGE_HPP
