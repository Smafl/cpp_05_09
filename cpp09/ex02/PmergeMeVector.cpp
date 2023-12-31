
#include "PmergeMe.hpp"
#include <vector>

// tk = (2^(k+1) + (-1)^k) / 3
std::size_t getTkV(std::size_t k) {
	if (k % 2 == 0)
		return ((1 << (k + 1)) + 1) / 3;
	else
		return ((1 << (k + 1)) - 1) / 3;
}

std::size_t binarySearchV(PairBase *el, const std::vector<PairBase*> &ar, std::size_t start, std::size_t end) {
	if (end - start == 1) {
		if (start >= ar.size())
			return start;
		else if (el->getNbr() > ar[start]->getNbr())
			return end;
		return start;
	}
	std::size_t mid = (start + end) / 2;
	if (mid >= ar.size())
		return binarySearchV(el, ar, start, mid);
	if (el->getNbr() == ar[mid]->getNbr())
		return mid;
	else if (el->getNbr() > ar[mid]->getNbr())
		return binarySearchV(el, ar, mid + 1, end);
	else
		return binarySearchV(el, ar, start, mid);
}

// this function is doing actual sorting
void miSortV(std::vector<PairBase*> &input) {
	std::size_t n = input.size();
	if (n <= 1)
		return;

//	make pairs
	std::vector<PairBase*> pair;
	for (std::size_t i = 0; i + 1 < n; i += 2) {
		Pair *p = new Pair(input[i], input[i + 1]);
		pair.push_back(p);
	}
	miSortV(pair);

//	create main chain and pend chain
	std::vector<PairBase*> sorted;
	std::vector<PairBase*> linked;
	sorted.push_back(dynamic_cast<Pair*>(pair[0])->getMin());
	for (std::size_t i = 0; i != pair.size(); i++) {
		sorted.push_back(dynamic_cast<Pair*>(pair[i])->getMax());
		linked.push_back(dynamic_cast<Pair*>(pair[i])->getMin());
		delete pair[i];
	}

//	push in pend chain unpair element
	if (n % 2 != 0)
		linked.push_back(input[n - 1]);

//	insert from pend chain to main chain
	bool flag = false;
	for (std::size_t k = 2; !flag; k++) {
		std::size_t tk = getTkV(k);
		std::size_t tk2 = getTkV(k - 1);
		for (std::size_t i = tk; i != tk2; i--) {
			// linked[i-1] insert in sorted with binary search before (2^k)-1
			if (i - 1 >= linked.size()) {
				flag = true;
				continue;
			}
			std::size_t insertIndex = binarySearchV(linked[i - 1], sorted, 0, (1 << k) - 1);
			sorted.insert(sorted.begin() + insertIndex, linked[i - 1]);
		}
	}
	input.swap(sorted);
}

// this function is called in main()
// std::vector<PairBase*> is made from vector<int> from input
// then sorting
// then unwrapped std::vector<PairBase*> to vector<int> back
void sortVector(std::vector<int> &input) {
	std::vector<PairBase*> pairBase;
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); it++) {
		Unpair *nbr = new Unpair(*it);
		pairBase.push_back(nbr);
	}

	miSortV(pairBase);

	for (std::size_t i = 0; i != pairBase.size(); i++) {
		input[i] = pairBase[i]->getNbr();
		delete pairBase[i];
	}
}
