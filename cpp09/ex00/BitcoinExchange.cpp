
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>	// open file with ifstream
#include <time.h>	// strptime
#include <string>	// c_str
#include <sstream>	// std::istringstream

void getInputData(char *input) {
//	ifstream constructor constructs an object and open a file
//	this file will be closed in destructor (no need to close it manually)
	std::ifstream inputFile(input);
	if (inputFile.rdstate() & std::ifstream::failbit) {
		throw BtcExceptions(BtcExceptions::CANNOTOPENINPUTFILE);
	}
}

// constructors and destructor
BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	_exchangeRates(other._exchangeRates) { }

BitcoinExchange::~BitcoinExchange() { }

// operator=
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		BitcoinExchange newObj(other);
		newObj._exchangeRates.swap(_exchangeRates);
	}
	return *this;
}

void BitcoinExchange::getDatabase() {
	std::fstream data("data.csv");

	if (data.rdstate() & std::ifstream::failbit) {
		throw BtcExceptions(BtcExceptions::CANNOTOPENDATABASE);
	}

	BitcoinExchange exchangeRates;
	// struct tm tmDate;
	std::string strDate;
	float rate;
	for (std::string line; std::getline(data, line);) {
		if (line.empty() || !line.compare("date,exchange_rate"))
			continue;
		std::istringstream is;
		if (std::getline(is, strDate, ',')) {
			if (is >> rate)
				_exchangeRates[strDate] = rate;
			else {
				std::cout << "check date" << std::endl;
				throw BtcExceptions(BtcExceptions::INVALIDDATA);
			}
		}
		else {
			std::cout << "check getline" << std::endl;
			throw BtcExceptions(BtcExceptions::INVALIDDATA);
		}
	}
}
