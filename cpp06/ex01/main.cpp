
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data *data = new Data;
	data->nbr = 15;
	data->str = "Hi";
	uintptr_t ptr = 0;

	ptr = Serializer::serialize(data);
	std::cout << ptr << std::endl;

	data = Serializer::deserialize(ptr);
	std::cout << "number: " << data->nbr << std::endl;
	delete data;
	return 0;
}
