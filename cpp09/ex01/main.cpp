
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: expected inverted Polish mathematical expression as an argument" << std::endl;
        return 1;
    }
    Calc result(argv[1]);
    return 0;
}
