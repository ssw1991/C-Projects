#include <iostream>
#include <limits>

template <typename T>
T Epsilon()
{
	T epsilon(1);
	while ((1.0 + 0.5*epsilon) != 1.0)
	{
		epsilon *= 0.5;
	}
	return epsilon;
}


int main()
{

	double e = Epsilon<double>();
	std::cout << e << std::endl;
	std::cout << std::numeric_limits<double>::epsilon();

}