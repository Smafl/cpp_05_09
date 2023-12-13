
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **)
{
	if (argc != 2) {
		std::cerr << "Error: expected a file with input data" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		BitcoinExchange dataBase("tempdata.csv");
		std::cout << dataBase.getRate(Date(1024,2,29)) << std::endl;
	} catch (const BtcExceptions &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
