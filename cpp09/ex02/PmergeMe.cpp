
#include "PmergeMe.hpp"
#include <vector>
#include <cmath>	// pow()

int get_tk(int k) {
	return (std::pow(2, k + 1) + std::pow(-1, k)) / 3;
}

// this function is doing actual sorting
void mi_sort(std::vector<PairBase*> &input) {
	std::size_t n = input.size();
	std::vector<PairBase*> pair;
	for (std::size_t i = 0; i + 1 < n; i += 2) {
		Pair *p = new Pair(input[i], input[i + 1]);
		pair.push_back(p);
	}
	mi_sort(pair);

	std::vector<PairBase*> sorted;
	std::vector<PairBase*> linked;
	sorted.push_back(dynamic_cast<Pair*>(pair[0])->getMin());
	for (std::size_t i = 0; i != pair.size(); i++) {
		sorted.push_back(dynamic_cast<Pair*>(pair[i])->getMax());
		linked.push_back(dynamic_cast<Pair*>(pair[i])->getMin());
		delete pair[i];
	}
	if (n % 2 != 0)
		linked.push_back(input[n - 1]);

	int index;
	int tk;
	int tk2;

	for (int k = 2; ; k++) {
		tk = get_tk(k);
		tk2 = get_tk(k - 1);
		for (int i = tk; i != tk2; i--) {

		}
	}
}

// this function is called in main()
// std::vector<PairBase*> is made from vector<int> from input
// then sorting
// then unwrapped std::vector<PairBase*> to vector<int> back
void sort(std::vector<int> &input) {
	std::vector<PairBase*> pairBase;
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); it++) {
		Unpair *nbr = new Unpair(*it);
		pairBase.push_back(nbr);
	}

	mi_sort(pairBase);

	for (std::size_t i = 0; i != pairBase.size(); i++) {
		input[i] = pairBase[i]->getNbr();
		delete pairBase[i];
	}
}
