
#include "PmergeMe.hpp"
#include <sstream>	// std::istringstream
#include <iostream>	// std::cout

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(char **argv) {
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
			_vec.push_back(nbr);
			is >> std::ws;
		}
		i++;
	}
}

PmergeMe::~PmergeMe() { }

void PmergeMe::printVector() const {
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << " ";
	}
}
