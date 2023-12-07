
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>	// open file with ifstream

void getInputData(char *input) {
//	ifstream constructor constructs an object and open a file
//	this file will be closed in destructor (no need to close it manually)
	std::ifstream inputFile(input);
	if (inputFile.rdstate() & std::ifstream::failbit) {
		throw BtcExceptions(BtcExceptions::CANNOTOPENINPUTFILE);
	}
	BitcoinExchange exchangeRates;
	std::string date;
	std::string line;
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

// getters
