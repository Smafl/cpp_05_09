
#include "BitcoinExchange.hpp"
#include "BtcExceptions.hpp"
#include <iostream>
#include <fstream>	// open file with ifstream
#include <sstream>	// std::istringstream
#include <map>		// find

// constructors and destructor
BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const std::string &fileName) {
	std::fstream data(fileName);
	if (data.rdstate() & std::ifstream::failbit)
		throw BtcExceptions(BtcExceptions::CANNOT_OPEN_DATABASE);

	int count = 0;
	for (std::string line; std::getline(data, line);) {
		count++;
		if (line.empty() || count == 1)
			continue;
		std::istringstream is(line);
		try {
			float rate;
			Date date;
			is >> date;
			if (!is.good())
				throw BtcExceptions(BtcExceptions::INVALID_DATE);
			std::cout << date.getYear() << " " << date.getMonth() << " " << date.getDay() << " ";
			is.ignore(1, ',');
			is >> rate;
			std::cout << rate << std::endl;
			if (!is.good() && !is.eof())
				throw BtcExceptions(BtcExceptions::INVALID_DATA);
			_exchangeRates[date] = rate;
		} catch (const BtcExceptions &e) {
			std::cerr << e.what() << " in line " << count << std::endl;
		}
	}
}

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

float BitcoinExchange::getRate(const Date &) const {
	return 0;
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

/*
// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  
  mymap['b']=40;
  mymap['c']=60;
  mymap['e']=100;

  itlow=mymap.lower_bound ('a'); // b -> exception
  itlow=mymap.lower_bound ('b'); // b
  itlow=mymap.lower_bound ('c'); // c
  itlow=mymap.lower_bound ('d'); // e
  itlow=mymap.lower_bound ('e'); // e
  itlow=mymap.lower_bound ('f'); // mymap::end() -> mymap.rbegin()
std::cout << 
  

  return 0;
}
*/
