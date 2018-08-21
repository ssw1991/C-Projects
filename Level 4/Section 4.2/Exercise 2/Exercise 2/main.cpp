#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

using value_type = double;
using Vector = std::vector<value_type>;



auto BinPred2 = std::less_equal<value_type>();
auto BinPred3 = std::greater<value_type>();  // Check strict decending 



int main()
{
	Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered
	Vector vec9{ 10.0, -4.0, 3.0, 2.0, 1.0 }; // Not ordered

	Vector vec1{ -4.0, 1.0, 2.0, 3.0, 10.0 }; 
	Vector vec2{ 10.0, 3.0, 2.0, 1.0, -4.0 };


	auto pos = std::is_sorted_until(vec8.begin(), vec8.end());
	std::cout << "bad value: " << *pos << std::endl;

	pos = std::is_sorted_until(vec9.begin(), vec9.end(), BinPred3);
	std::cout << "bad value: " << *pos << std::endl;

	std::cout << "Is sorted acending: " << std::is_sorted(vec1.begin(), vec1.end(), BinPred2) << std::endl;
	std::cout << "Is sorted decending: " << std::is_sorted(vec1.begin(), vec1.end(), BinPred3) << std::endl;


	std::cout << "Is sorted acending: " << std::is_sorted(vec2.begin(), vec2.end(), BinPred2) << std::endl;
	std::cout << "Is sorted decending: " << std::is_sorted(vec2.begin(), vec2.end(), BinPred3) << std::endl;

	std::sort(vec9.begin(), vec9.end(), BinPred3); // Sort strictly decending

	for (auto a : vec9) 
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

	std::sort(vec9.begin(), vec9.end(), BinPred2);  // Sort ascending

	for (auto a : vec9)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

	Vector vec4 = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };

	std::partial_sort(vec4.begin(), vec4.begin() + 5, vec4.end(), BinPred2);  // Elements before middle will be smallest, sorted acending
	for (auto a : vec4)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

	std::partial_sort(vec4.begin(), vec4.begin() + 5, vec4.end(), BinPred3);  // Elements before middle will be largest, sorted decending
	for (auto a : vec4)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

}