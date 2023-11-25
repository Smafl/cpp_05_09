
#include "Array.hpp"
#include <iostream>
#include <stdexcept>

int foo(const Array<int> &a) {
	return a[0] + a[1];
}

int main()
{
	Array<int> iArray(10);
	printArray(iArray);
	Array<int> i2Array(20);
	i2Array[3] = 51;
	swap(iArray, i2Array);
	i2Array = iArray;
	Array<char> cArray(15);
	Array<float> fArray(5);
	try {
		iArray[5] = 378634;
		printArray(i2Array);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
