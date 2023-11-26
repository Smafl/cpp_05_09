
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <map>
#include <algorithm> // std::find

template <typename T>
typename T::iterator easyfind(T &t, int i) {
	return std::find(t.begin(), t.end(), i);
}

template <typename T, typename F>
typename std::map<T, F>::iterator easyfind(std::map<T, F> &m, const T &key) {
	return m.find(key);
}

#endif // EASYFIND_HPP
