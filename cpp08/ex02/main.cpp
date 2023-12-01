
#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
    MutantStack<int> msInt;
    MutantStack<char> msChar;
    msInt.push(5);
    msInt.push(10);
    std::cout << "Top is " << msInt.top() << std::endl;
    std::cout << "Size is " << msInt.size() << std::endl;
    return 0;
}
