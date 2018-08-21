#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <functional>


using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;
using value_type = double;
using Vector = std::vector<value_type>;


Result find_sequential_greater(const Vector& v, value_type x)
{
	for (std::size_t j = 0; j < v.size(); ++j)
	{
		if (v[j] <= x && v[j + 1] > x)
		{
			return std::make_tuple(
				std::make_tuple(j, j + 1), true);
		}
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
}


Result find_if(const Vector& v, value_type x)
{ // Finds index to first number > 	
	auto f = std::bind(std::greater<value_type>(), std::placeholders::_1, x);
	auto i = std::find_if(v.begin(), v.end(), f);
	auto index = std::distance(v.begin(), i);
	if (i != v.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
}


Result lower_bound(const Vector& v, value_type x)
{ // Finds index to first number > 
	auto i = std::lower_bound(v.begin(), v.end(), x,std::less_equal<value_type>());
	auto index = std::distance(v.begin(), i);
	if (i != v.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

Result upper_bound(const Vector& v, value_type x)
{ // Finds first number >
	auto i = std::upper_bound(v.begin(), v.end(), x, std::less<value_type>()); // Replaced comparator to be less than rather than <=
	auto index = std::distance(v.begin(), i);
	if (i != v.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

Result equal_range(const Vector& v, value_type x)
{ // Finds index to first number >
	auto range = std::equal_range(v.begin(), v.end(), x);
	auto index = std::distance(v.begin(), range.second);
	if (range.first != v.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

Result find_if_not(const Vector& v, value_type x)
{ // Finds index to first number >
	auto f = std::bind(std::greater<value_type>(), std::placeholders::_1, x);
	auto i = std::find_if(v.begin(), v.end(), f);

	auto index = std::distance(v.begin(), i);
	if (i != v.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

int main()
{
	
	Vector v = { 1.,1.,2.,3.,4.,5.,7.,8. };

	Result r1 = find_sequential_greater(v, 3.0);
	Result r2 = find_if(v, 3.0);
	Result r3 = lower_bound(v, 3.0);
	Result r4 = upper_bound(v, 3.0);
	Result r5 = equal_range(v, 3.0);
	Result r6 = find_if_not(v, 3.0);


	std::cout << "Result 1: " << std::get<1>(std::get<0>(r1)) << std::endl;
	std::cout << "Using find_if: " << std::get<1>(std::get<0>(r2)) << std::endl;
	std::cout << "Using lower_bound: " << std::get<1>(std::get<0>(r3)) << std::endl;
	std::cout << "Using upper_bound: " << std::get<1>(std::get<0>(r4)) << std::endl;
	std::cout << "Using equal range: " << std::get<1>(std::get<0>(r5)) << std::endl;
	std::cout << "Using find_if_not: " << std::get<1>(std::get<0>(r6)) << std::endl;
	


	return 0;
}