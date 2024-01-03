
#include "PmergeMe.hpp"

// PAIR BASE
PairBase::PairBase() { }

PairBase::PairBase(const PairBase &) { }

PairBase &PairBase::operator=(const PairBase &) {
	return *this;
}

PairBase::~PairBase() { }


// PAIR
Pair::Pair() { }

Pair::Pair(PairBase *f, PairBase *s) {
	if (f->getNbr() > s->getNbr()) {
		_max = f;
		_min = s;
	}
	else {
		_max = s;
		_min = f;
	}
}

Pair::Pair(const Pair &) { }

Pair &Pair::operator=(const Pair &) {
	return *this;
}

Pair::~Pair() { }

int Pair::getNbr () const {
	return _max->getNbr();
}

PairBase *Pair::getMax() const {
	return _max;
}

PairBase *Pair::getMin() const {
	return _min;
}

// UNPAIR
Unpair::Unpair() { }

Unpair::Unpair(int nbr) :
	_nbr(nbr) { }

Unpair::Unpair(const Unpair &) { }

Unpair &Unpair::operator=(const Unpair &) {
	return *this;
}

Unpair::~Unpair() { }

int Unpair::getNbr() const {
	return _nbr;
}
