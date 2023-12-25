
#include "PmergeMe.hpp"
#include <vector>

void sort(std::vector<PairBase*> &input) {
	std::size_t n = input.size();
	std::vector<PairBase*> pair;
	for (std::size_t i = 0; i + 1 < n; i += 2) {
		Pair *p = new Pair(input[i], input[i + 1]);
		pair.push_back(p);
	}
	sort(pair);

	std::vector<PairBase*> sorted;
	std::vector<PairBase*> linked; // b1 b2 b3 ...
	// b3 = linked[2]
	// t1 = 1 -> 0
	// t2 = 3 -> 2
	sorted.push_back(dynamic_cast<Pair*>(pair[0])->getMin());
	for (std::size_t i = 0; i != pair.size(); i++) {
		sorted.push_back(dynamic_cast<Pair*>(pair[i])->getMax());
		linked.push_back(dynamic_cast<Pair*>(pair[i])->getMin());
		delete pair[i];
	}
	if (n % 2 != 0)
		linked.push_back(input[n - 1]);
}

void sort(std::vector<int> &input) {
	std::vector<PairBase*> pairBase;
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); it++) {
		Unpair *nbr = new Unpair(*it);
		pairBase.push_back(nbr);
	}

	sort(pairBase);

	for (std::size_t i = 0; i != pairBase.size(); i++) {
		input[i] = pairBase[i]->getNbr();
		delete pairBase[i];
	}
}

/*
[ *     ][ *     ][ *     ]
  |        |        |    
  v        v        v    
  Unpair   Unpair   Unpair
*/
