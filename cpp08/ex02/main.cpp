
#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
    MutantStack<int> msInt;
    msInt.push(5);
    msInt.push(10);
    std::cout << "Top is " << msInt.top() << std::endl;
    std::cout << "Size is " << msInt.size() << std::endl;
	for (int i = 0; i != 23; i++) {
		msInt.push(i + 1);
	}
	std::cout << *msInt.it_begin() << std::endl;
	for (MutantStack<int>::container_type::iterator it = msInt.it_begin(); it != msInt.it_end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

    // MutantStack<char> msChar;
	// for (int i = 0; i != 23; i++) {
	// 	msChar.push(i + 55);
	// }
	// for (MutantStack<char>::container_type::iterator it = msChar.it_begin(); it != msChar.it_end(); it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	// for (MutantStack<char>::container_type::reverse_iterator rit = msChar.it_rbegin(); rit != msChar.it_rend(); rit++) {
	// 	std::cout << *rit << " ";
	// }
	// std::cout << std::endl;
	// MutantStack<char>::container_type::reverse_iterator rit = msChar.it_rbegin();
	// *rit = 'x';
	// for (MutantStack<char>::container_type::reverse_iterator rit = msChar.it_rbegin(); rit != msChar.it_rend(); rit++) {
	// 	std::cout << *rit << " ";
	// }
	// std::cout << std::endl;

	// MutantStack<char>::container_type::const_reverse_iterator rit_const = msChar.it_rend_const() - 1;
	// std::cout << *rit_const << std::endl;
	// *rit_const = 'x';
    return 0;
}
