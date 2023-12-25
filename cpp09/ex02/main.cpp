
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>	// std::istringstream
#include <vector>

void printInput(const std::vector<int> &input) {
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void getInput(std::vector<int> &input, char **argv) {
	int i = 1;
	while (argv[i]) {
		std::istringstream is(argv[i]);
		int nbr;
		while (is.good()) {
			is >> nbr;
			if (is.fail())
				throw Exception(Exception::BAD_INPUT);
			if (nbr < 0)
				throw Exception(Exception::BAD_INPUT);
			input.push_back(nbr);
			is >> std::ws;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: expected a positive integer sequence as argument" << std::endl;
		return EXIT_FAILURE;
	}
	std::vector<int> input;
	try {
		getInput(input, argv);
		printInput(input);
		sort(input);
	} catch (const Exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
