
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected a file with input data." << std::endl;
		return EXIT_FAILURE;
	}
	if (exchanging(argv[1]) == 1)
		return EXIT_FAILURE;
	// BitcoinExchange bar, foo;
	// bar["a"] = 11;
	// bar["ab"] = 22;
	// bar["abc"] = 33;
	// foo = bar;
	// std::cout << "foo contains:\n";
	// for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
	return 0;
}
