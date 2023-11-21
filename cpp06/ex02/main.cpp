
#include "Base.hpp"
#include "Identify.hpp"
#include <iostream>

int main()
{
	Base *someClass = generate();
	identify(someClass);
	identify(*someClass);
	return 0;
}
