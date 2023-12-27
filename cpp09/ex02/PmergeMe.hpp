
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PairBase {
protected:
	PairBase();
	PairBase(const PairBase &other);
	PairBase &operator=(const PairBase &other);
public:
	virtual ~PairBase();
	virtual int getNbr() const = 0;
};

class Pair : public PairBase {
private:
	Pair();
	Pair(const Pair &other);
	Pair &operator=(const Pair &other);
	PairBase *_max;
	PairBase *_min;
public:
	Pair(PairBase *f, PairBase *s);
	~Pair();
	int getNbr () const;
	PairBase *getMax() const;
	PairBase *getMin() const;
};

class Unpair : public PairBase {
private:
	int _nbr;
	Unpair();
	Unpair(const Unpair &other);
	Unpair &operator=(const Unpair &other);
public:
	explicit Unpair(int nbr);
	~Unpair();
	int getNbr() const;
};

void sortVector(std::vector<int> &input);
void sortDeque(std::deque<int> &input);

#endif // PMERGEME_HPP

// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
