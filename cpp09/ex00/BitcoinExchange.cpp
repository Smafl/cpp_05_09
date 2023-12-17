
#include "BitcoinExchange.hpp"
#include "BtcExceptions.hpp"
#include <iostream>
#include <fstream>	// open file with std::fstream
#include <sstream>	// std::istringstream
#include <limits>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const std::string &fileName) {
	std::fstream data(fileName);
	if (!data.good())
		throw OpenFileException(OpenFileException::DATABASE);

	int count = 0;
	for (std::string line; std::getline(data, line);) {
		count++;
		if (line.empty() || count == 1)
			continue;
		std::istringstream is(line);
		Date date;
		float rate;
		try {
			is >> date;
		} catch (const DateException &e) {
			throw DataBaseException(DataBaseException::INVALID_DATE, count);
		}
		if (!is.good())
			throw DataBaseException(DataBaseException::INVALID_DATE, count);
		if (!date.dateIsValid())
			throw DataBaseException(DataBaseException::INVALID_DATE, count);
		is.ignore(1, ',');
		is >> rate;
		if (is.fail())
			throw DataBaseException(DataBaseException::INVALID_DATA, count);
		if (!is.good() && !is.eof())
			throw DataBaseException(DataBaseException::INVALID_DATA, count);
		if (rate > std::numeric_limits<float>::max())
			throw DataBaseException(DataBaseException::RATE_OUT_OF_RANGE, count);
		if (rate < 0)
			throw DataBaseException(DataBaseException::NEGATIVE_RATE, count);
		_exchangeRates[date] = rate;
	}
	if (count == 0 || count == 1)
		throw DataBaseException(DataBaseException::EMPTY_DATABASE, count);
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
	try {
		if (date == it->first)
			return it->second;
		else if (date < it->first) {
			if (it == _exchangeRates.begin())
				throw InputDataException(InputDataException::DATE_IS_TOO_EARLY);
			it--;
			return it->second;
		}
		else if (it == _exchangeRates.end())
			return _exchangeRates.rbegin()->second;
	} catch (const InputDataException &e) {
		std::cerr << e.what() << " => " << it->first.getYear() << "-" << it->first.getMonth() << "-" << it->first.getDay() << std::endl;
	}
	return it->second;
}

void exchange(char *inputFile, BitcoinExchange &dataBase) {
//	ifstream constructor constructs an object and open a file
//	this file will be closed in destructor (no need to close it manually)
	std::ifstream input(inputFile);
	if (!input.good())
		throw OpenFileException(OpenFileException::INPUTFILE);

	int count = 0;
	for (std::string line; std::getline(input, line);) {
		try {
			count++;
			if (line.empty() || count == 1)
				continue;
			std::istringstream is(line);
			Date date;
			float btc;
			std::stringstream badInput;
			try {
				is >> date;
			} catch (const DateException &e) {
				throw InputDataException(InputDataException::BAD_INPUT);
			}
			if (!is.good())
				throw InputDataException(InputDataException::BAD_INPUT);
			if (!date.dateIsValid())
				throw InputDataException(InputDataException::BAD_INPUT);
			is.ignore(3, '|');
			is >> btc;
			if (!is.good() && !is.eof())
				throw InputDataException(InputDataException::BAD_INPUT);
			if (btc > 1000)
				throw InputDataException(InputDataException::BTC_OUT_OF_RANGE);
			if (btc < 0)
				throw InputDataException(InputDataException::NEGATIVE_AMOUNT_BTC);
			printExchange(date, btc, dataBase);
		} catch (const InputDataException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void printExchange(const Date &date, float btc, BitcoinExchange &dataBase) {
	std::cout << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	std::cout << " => " << btc << " = ";
	std::cout << dataBase.getRate(date) * btc << std::endl;
}
