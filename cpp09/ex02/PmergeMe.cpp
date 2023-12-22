
#include "PmergeMe.hpp"
#include <sstream>	// std::istringstream
#include <iostream>	// std::cout

PmergeVector::PmergeVector() :
	_unpairInt(-1) { }

PmergeVector::~PmergeVector() { }

void PmergeVector::getInput(char **argv) {
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
			_input.push_back(nbr);
			is >> std::ws;
		}
		i++;
	}
}

void PmergeVector::makePair() {
	std::size_t lenInput = _input.size();
	std::size_t lenPair = lenInput / 2;

	for (std::size_t i = 0; lenPair != 0; lenPair--) {
		if (_input[i] > _input[i + 1])
			_pairs.push_back(std::make_pair(_input[i], _input[i + 1]));
		else
			_pairs.push_back(std::make_pair(_input[i + 1], _input[i]));
		i += 2;
	}
	for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++) { // delete
		std::cout << "(" << it->first << "," << it->second << ")" << " ";
	}
	if (lenInput % 2 != 0) {
		_unpairInt = _input[lenInput - 1];
		std::cout << "; unpair: " << _unpairInt; // delete
	}
}

void PmergeVector::printVector() const {
	for (std::vector<int>::const_iterator it = _input.begin(); it != _input.end(); it++) {
		std::cout << *it << " ";
	}
}

// PmergeList::PmergeList() { }

// PmergeList::PmergeList(char **argv) {
// 	int i = 1;
// 	while (argv[i]) {
// 		std::istringstream is(argv[i]);
// 		int nbr;
// 		while (is.good()) {
// 			is >> nbr;
// 			if (is.fail())
// 				throw Exception(Exception::BAD_INPUT);
// 			if (nbr < 0)
// 				throw Exception(Exception::BAD_INPUT);
// 			_list.push_back(nbr);
// 			is >> std::ws;
// 		}
// 		i++;
// 	}
// }

// PmergeList::~PmergeList() { }

// void PmergeList::printList() const {
// 	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++) {
// 		std::cout << *it << " ";
// 	}
// }
