
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data {
	int nbr;
	std::string str;
};

class Serializer {
public:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	
	Serializer &operator=(const Serializer &other);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
