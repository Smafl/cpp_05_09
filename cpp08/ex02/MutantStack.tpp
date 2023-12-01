
template <class T>
MutantStack<T>::MutantStack() { }

template <class T>
MutantStack<T>::MutantStack(const MutantStack &other) :
    _stack(other._stack) { }

template <class T>
MutantStack<T>::~MutantStack() { }

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
    if (*this != other)
        _stack = other._stack;
    return *this;
}

// template <typename T, typename Container>
// class Stack
// {
//     public:

//     protected:
//         Container c;
// };

// mutantstack::iterator

// using iterator = Container::iterator;