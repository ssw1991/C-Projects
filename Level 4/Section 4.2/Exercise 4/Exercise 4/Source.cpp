#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <functional>


std::map<int, int> Mapper(std::vector<int>& v)
{ // For each element in the vector increment its count in the map
	// if its not in the map it will set to 1
	std::map<int, int> m;
	for (auto i: v)
	{
		++m[i];
	}
	return m;
}

std::tuple<int, int, int, double> Stats(std::vector<int>& v)
{
	auto min = *std::min_element(v.begin(), v.end());
	auto max = *std::max_element(v.begin(), v.end());
	auto sum = std::accumulate(v.begin(), v.end(), 0);
	double average = 1.0*sum / v.size();  // mult by 1.0 to force avoid int div

	return std::make_tuple(min, max, sum, average);
}

bool equal(int i1, int i2)
{
	return i1 == i2;
}
int main()
{
	std::vector<int> v = { 1,2,4,5,4,1};
	auto map = Mapper(v);

	for (auto i : map)
	{
		std::cout << i.first << ": " << i.second << std::endl;
	}

	auto stats = Stats(v);

	std::cout << "Min: " << std::get<0>(stats) << " Max: " << std::get<1>(stats)
		<< " Sum: " << std::get<2>(stats) << " Average: " << std::get<3>(stats) << std::endl;

	std::vector<int> v1 = { 1,2,-3,4,5,5,5,6 };

	auto i = std::find(v1.begin(), v1.end(), 5);
	std::cout << "5 occurs at index: " << std::distance(v1.begin(), i) <<std::endl;
	int val = 2;
	auto Func1 = std::bind2nd(std::ptr_fun(&equal), val);    // Had to use ptr_fun to avoid error
	auto Func2 = std::bind(equal, std::placeholders::_1, 2);  // Using current bind
	auto LambdaFunc = [](int i) {return i == 2; };            // return true if equal to 2

	
	
	// C
	i = std::find_if(v1.begin(), v1.end(), Func1);
	std::cout << "2 occurs at index: " << std::distance(v1.begin(), i) << std::endl;
	
	i = std::find_if(v1.begin(), v1.end(), Func2);
	std::cout << "2 occurs at index: " << std::distance(v1.begin(), i) <<std::endl;

	i = std::find_if(v1.begin(), v1.end(), LambdaFunc);
	std::cout << "2 occurs at index: " << std::distance(v1.begin(), i) << std::endl;
	

	//D 
	
	std::vector<int> v3 = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };
	std::vector<int> target = { 3,4,5 };

	i = std::search_n(v3.begin(), v3.end(), 3, 5);   // Iterator to first element where 3 5's occur
	std::cout << "The position of the first of 3 5's is: " << std::distance(v3.begin(), i) << std::endl;

	i = std::adjacent_find(v3.begin(), v3.end());    // First Element that is duplicate
	std::cout << "The position of the first duplicate is: " << std::distance(v3.begin(), i) << std::endl;

	i = std::search(v3.begin(), v3.end(), target.begin(), target.end());  // Finds iterator to first element of subrange
	std::cout << "The position of the first {3, 4, 5} 5's is: " << std::distance(v3.begin(), i) << std::endl;

	i = std::find_end(v3.begin(), v3.end(), target.begin(), target.end());  //Finds iterator to first element of last subrange
	std::cout << "The position of the last {3, 4, 5} 5's is: " << std::distance(v3.begin(), i) << std::endl;

	target = { 1,2,5 };

	std::cout << "F: are the ranges equal: " << std::equal(v3.begin(), v3.end(), target.begin(),target.end());
}