
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Date.hpp"
#include "BtcExceptions.hpp"
#include <map>
#include <fstream>

class BitcoinExchange {
private:
	std::map<Date,float> _exchangeRates;
public:
	BitcoinExchange();
	explicit BitcoinExchange(const std::string &fileName);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	float getRate(const Date &date) const;
};

void exchange(char *inputFile, BitcoinExchange &dataBase);
void printExchange(const Date &date, float btc, BitcoinExchange &dataBase);

#endif // BITCOINEXCHANGE_HPP

/*
errors:
- empty files
- negativ rate or amount of btc
- wrong date
- take error from subject ?
- no valid dates

- check subject for input requarement
*/
