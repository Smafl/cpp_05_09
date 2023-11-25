
#include "iter.hpp"
#include <iostream>

class Example {
private:
	int _inc;
public:
	Example(int inc) : _inc(inc) { };

	int operator()(int &i) {
		return i += _inc;
	}
};

int main()
{
	int intArray[5] = {1, 2, 3, 4, 5};
	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};

	std::size_t len = 5;
	iter(intArray, len, plusOne<int>);
	printArray(intArray, len);
	Example example(10);
	iter(intArray, len, example);
	printArray(intArray, len);
	printArray(charArray, len);
	iter(charArray, len, plusOne<char>);
	printArray(charArray, len);

	return 0;
}
