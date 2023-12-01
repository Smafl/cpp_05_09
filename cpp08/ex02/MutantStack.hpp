
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() { }
    MutantStack(const MutantStack &) { }
    ~MutantStack() { }

    MutantStack &operator=(const MutantStack &other) {
		if (*this != other)
			this->c = other.c;
		return *this;
	}

//	iterators
	typename std::stack<T>::container_type::iterator it_begin() {
		return std::stack<T>::c.begin();
	}

	typename std::stack<T>::container_type::iterator it_end() {
		return std::stack<T>::c.end();
	}

	typename std::stack<T>::container_type::const_iterator it_begin_const() const {
		return std::stack<T>::c.begin();
	}

	typename std::stack<T>::container_type::const_iterator it_end_const() const {
		return std::stack<T>::c.end();
	}

//	reverse iterators
	typename std::stack<T>::container_type::reverse_iterator it_rbegin() {
		return std::stack<T>::c.rbegin();
	}

	typename std::stack<T>::container_type::reverse_iterator it_rend() {
		return std::stack<T>::c.rend();
	}

	typename std::stack<T>::container_type::const_reverse_iterator it_rbegin_const() const {
		return std::stack<T>::c.rbegin();
	}

	typename std::stack<T>::container_type::const_reverse_iterator it_rend_const() const {
		return std::stack<T>::c.rend();
	}
};

#endif // MUTANTSTACK_HPP
