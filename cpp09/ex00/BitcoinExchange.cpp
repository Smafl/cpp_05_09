
#include "BitcoinExchange.hpp"
#include "BtcExceptions.hpp"
#include <iostream>
#include <fstream>	// open file with std::fstream
#include <sstream>	// std::istringstream
#include <map>		// find
#include <limits>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const std::string &fileName) {
	std::fstream data(fileName);
	if (data.rdstate() & std::ifstream::failbit)
		throw BtcExceptions(BtcExceptions::CANNOT_OPEN_DATABASE);

	int count = 0;
	try {
		for (std::string line; std::getline(data, line);) {
			count++;
			if (line.empty() || count == 1)
				continue;
			std::istringstream is(line);
			Date date;
			float rate;
			is >> date;
			if (!is.good())
				throw BtcExceptions(BtcExceptions::INVALID_DATE);
			if (!date.dateIsValid())
				throw BtcExceptions(BtcExceptions::INVALID_DATE);
			std::cout << date.getYear() << " " << date.getMonth() << " " << date.getDay() << " ";
			is.ignore(1, ',');
			is >> rate;
			std::cout << rate << std::endl;
			if (!is.good() && !is.eof())
				throw BtcExceptions(BtcExceptions::INVALID_DATA);
			if (rate > std::numeric_limits<float>::max())
				throw BtcExceptions(BtcExceptions::RATE_OUT_OF_RANGE);
			if (rate < 0)
				throw BtcExceptions(BtcExceptions::NEGATIVE_RATE);
			_exchangeRates[date] = rate;
		}
	} catch (const BtcExceptions &e) {
		std::cerr << e.what() << " in line " << count << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	_exchangeRates(other._exchangeRates) { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		BitcoinExchange newObj(other);
		newObj._exchangeRates.swap(_exchangeRates);
	}
	return *this;
}

float BitcoinExchange::getRate(const Date &date) const {
	std::map<Date,float>::const_iterator it = _exchangeRates.lower_bound(date);
	// std::cout << "lower_bound return: " << it->first.getYear() << "-" << it->first.getMonth() << "-" << it->first.getDay() << std::endl;
	try {
		if (date == it->first) {
			// std::cout << "date == " << std::endl;
			return it->second;
		}
		else if (date < it->first) {
			// std::cout << "date < " << std::endl;
			if (it == _exchangeRates.begin())
				throw BtcExceptions(BtcExceptions::DATE_IS_TOO_EARLY);
			it--;
			return it->second;
		}
		else if (it == _exchangeRates.end()) {
			// std::cout << "date == end()" << std::endl;
			return _exchangeRates.rbegin()->second;
		}
	} catch (const BtcExceptions &e) {
		std::cerr << e.what() << " => " << it->first.getYear() << "-" << it->first.getMonth() << "-" << it->first.getDay() << std::endl;
	}
	return it->second;
}

// void BitcoinExchange::getInputData(char *input) const {
// //	ifstream constructor constructs an object and open a file
// //	this file will be closed in destructor (no need to close it manually)
// 	std::ifstream inputFile(input);
// 	if (inputFile.rdstate() & std::ifstream::failbit)
// 		throw BtcExceptions(BtcExceptions::CANNOT_OPEN_INPUTFILE);

// 	std::string date;
// 	float nbrBtc;
// 	for (std::string line; std::getline(inputFile, line);) {
// 		if (line.empty() || !line.compare("date | value"))
// 			continue;
// 		std::istringstream is(line);
// 		if (std::getline(is, date, '|')) {
// 			std::map<std::string,float>::iterator it = _exchangeRates.find(date);
// 			// if (it == _exchangeRates.end()) // not found
// 		}
// 	}
// }
