
#include <functional>
#include <iostream>
double freeFunction3(double x, double y, double z)
{
	return x + y + z;
}

int main() {

	double x = 1.2;
	double y = 2.4;
	double z = 3.6;

	auto f0 = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	auto f1 = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, 4);
	auto f2 = std::bind(freeFunction3, std::placeholders::_1, 2, 4);
	auto f3 = std::bind(freeFunction3, 6, 2, 4);

	std::cout << f0(x, y, z) << std::endl;  //Arity 3 - uneccesary
	std::cout << f1(x, y) << std::endl;     // Arity 2 
	std::cout << f2(x) << std::endl;		// Arity 1
	std::cout << f3() << std::endl;         // Arity 0

	return 0;
}