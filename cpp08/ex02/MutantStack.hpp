
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
private:
    std::stack<T> _stack;
public:
    MutantStack();
    MutantStack(const MutantStack &other);
    ~MutantStack();

    MutantStack &operator=(const MutantStack &other);

};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
