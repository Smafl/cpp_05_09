
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::list<int> list;

public:
	PmergeMe();
	// PmergeMe(const PmergeMe &other);
	~PmergeMe();

	// PmergeMe &operator(const PmergeMe &other);
};

#endif // PMERGEME_HPP
