
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected a file with input data" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		BitcoinExchange dataBase("data.csv");
		exchange(argv[1], dataBase);
	} catch (const DataBaseException &e) {
		std::cout << e.what() << std::endl;
	} catch (const InputDataException &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
