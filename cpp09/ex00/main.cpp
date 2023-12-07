
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected a file with input data." << std::endl;
		return EXIT_FAILURE;
	}
	try {
		getInputData(argv[1]);
	} catch (const BtcExceptions &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
