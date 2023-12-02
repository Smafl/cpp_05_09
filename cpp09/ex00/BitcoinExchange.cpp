
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>	// open file with ifstream

int exchanging(char *input) {
//	ifstream constructor constructs an object and open a file
//	this file will be closed in destructor (no need to close it manually)
	std::ifstream inputFile(input);
	if (inputFile.rdstate() & std::ifstream::failbit) {
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	BitcoinExchange exchangeRates;

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
