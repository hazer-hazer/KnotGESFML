#ifndef MATH_H
#define MATH_H

#include <cstdlib>
#include <cmath>

std::srand(std::time(nullptr));

class Math {

	template <typename T>
	static float rand();
};

#endif