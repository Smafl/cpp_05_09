
#include "Array.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	Array<int> iArray(10);
	Array<int> i2Array;
	i2Array = iArray;
	Array<char> cArray(15);
	Array<float> fArray(5);
	try {
		iArray[5] = 378634;
		for (unsigned int i = 0; i != i2Array.size(); i++) {
			std::cout << i2Array[i] << " ";
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
