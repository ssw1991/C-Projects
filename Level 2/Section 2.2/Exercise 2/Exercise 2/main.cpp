#include <type_traits>
#include <array>
#include <complex>
#include <iostream>
#include <vector>



int main()
{
	std::vector<double> v;
	std::array<double, 4> a;
	double d;

	std::cout << std::is_array<decltype(v)>::value << std::endl;
	std::cout << std::is_array<decltype(a)>::value << std::endl;
	std::cout << std::is_array<decltype(d)>::value << std::endl;

	int my_array[1][3][4][5];

	std::cout << "Rank: " << std::rank<decltype(my_array)>::value << std::endl;
	std::cout << "Extent: " << std::extent<decltype(my_array), 3>::value << std::endl;

	std::remove_extent<decltype(my_array)>::type my_array2;
	std::cout << "Rank: " << std::rank<decltype(my_array2)>::value << std::endl;
	std::cout << "Extent: " << std::extent<decltype(my_array2), 0>::value << std::endl;  // first dimension removed

	std::remove_all_extents<decltype(my_array)>::type my_array3;
	std::cout << "Rank: " << std::rank<decltype(my_array3)>::value << std::endl;
	std::cout << "Extent: " << std::extent<decltype(my_array3), 0>::value << std::endl;  // all dimensions removed



	return 0;
}