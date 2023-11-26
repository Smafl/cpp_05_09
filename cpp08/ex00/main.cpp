
#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <map>

int main()
{
	std::cout << "---INTEGER---" << std::endl;
	std::array<int, 5> intArray = {5, 10, 15, 20, 25};
	std::array<int, 5>::iterator itInt = easyfind(intArray, 15);
	if (itInt != intArray.end())
		std::cout << *itInt << std::endl;
	else
		std::cout << "Element not found." << std::endl;

	std::cout << "---CHAR---" << std::endl;
	std::vector<char> charArray;
    charArray.push_back('a');
    charArray.push_back('b');
    charArray.push_back('c');
    charArray.push_back('d');
    charArray.push_back('e');
	std::vector<char>::iterator itChar = easyfind(charArray, 'm');
	if (itChar != charArray.end())
		std::cout << *itChar << std::endl;
	else
		std::cout << "Element not found." << std::endl;

	std::cout << "---MAP---" << std::endl;
	std::map<std::string, int> mapArray;
	mapArray.insert(std::make_pair("Aug", 144));
    mapArray.insert(std::make_pair("Sep", 80));
    mapArray.insert(std::make_pair("Oct", 112));
	std::map<std::string, int>::iterator itMap = easyfind(mapArray, std::string("Aug"));
	if (itMap != mapArray.end())
		std::cout << itMap->first << std::endl;
	else
		std::cout << "Element not found." << std::endl;
	return 0;
}
