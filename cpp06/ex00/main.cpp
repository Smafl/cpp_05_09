
#include "ScalarConverter.hpp"
#include <iostream>

// int main()
// {
// 	std::cout << "CHAR" << std::endl;
// 	ScalarConverter::convert(const_cast<char*>(" "));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("`"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("x"));
// 	std::cout << std::endl;
// 	std::cout << "INT" << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("0"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-0"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("100"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-2147483648"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("2147483647"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("2147483648"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-2147483649"));
// 	std::cout << std::endl;
// 	std::cout << "PSEUDO" << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("nan"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-inf"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("+inf"));
// 	std::cout << std::endl;
// 	std::cout << "DOUBLE" << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-2147.483649"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("21474836.49"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-678678234673467345678345678.76345676783456784534534534534578934578"));
// 	std::cout << std::endl;
// 	std::cout << "FLOAT" << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("-2147.483649f"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("21474836.49f"));
// 	std::cout << std::endl;
// 	ScalarConverter::convert(const_cast<char*>("45E+380"));
// 	return 0;
// }

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Expected input: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
