
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class Calc {
private:
    std::stack<int> _st;
public:
    Calc();
    // Calc(const Calc &other) { }
    explicit Calc(char *input);
    ~Calc();

    // Calc &operator=(const Calc &other) { }
};

#endif // RPN_HPP

// move constructors in .cpp

/*
- empty string
- out of range
- negative
- 3 numbers in a row
- 2 operations in a row
- number at the end of string without operation
*/
