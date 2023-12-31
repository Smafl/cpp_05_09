
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: expected inverted Polish mathematical expression as an argument" << std::endl;
        return EXIT_FAILURE;
    }
	try {
    	Calc result(argv[1]);
	} catch (const Exception &e) {
		std::cerr << e.what() << std::endl;
	}
    return EXIT_SUCCESS;
}
