
#include "Identify.hpp"
#include <iostream>
#include <cstdlib>	// for rand() and srand()
#include <ctime>	// for time()
#include <stdexcept>

Base *generate() {
	std::srand(std::time(0));
	int randInt = std::rand() % 3 + 1;

	switch (randInt)
	{
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
	}
	std::cout << "generate() failed" << std::endl;
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "invalid type" << std::endl;
}

void identify(Base &p) {
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception &e) { }
	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception &e) { }
	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception &e) {
		std::cout << "invalid type: " << e.what() << std::endl;
	}
}
