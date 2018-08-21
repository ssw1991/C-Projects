#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

double ChiSquare(std::vector<int>& v)
{/* v is a vector containing frequencies
 This implementation assumes the frequencies were 
 generated from a uniform dist
 */

	double n = std::accumulate(v.begin(), v.end(), 0);
	double e = n / v.size();

	double chisq = 0;

	for (auto i : v)
	{
		chisq += ((i - e)*(i - e) / e);
	}

	return chisq;
}

int main()
{
	std::map<int, int> chisqMap;   // map to hold output from chisq;
	std::mt19937 eng1;  // Random engine
	std::uniform_int_distribution<int> dist1(1, 10); // distribution


	std::vector<int> test1 = { 5,5,5,5,5 };
	std::vector<int> test2 = { 3,7,5,4,6 }; // 4,4,0,1,1

	std::cout << "Test on first vector: " << ChiSquare(test1) << std::endl;   // Should be 0
	std::cout << "Test on second vector: " << ChiSquare(test2) << std::endl;  // Should be 2


	for (int i = 0; i < 1000; i++)
	{
		std::map<int, int> map2;  // Map to hold frequency counts for a single experiment

		for (int j = 0; j < 100; j++)
		{
			++map2[dist1(eng1)];   // increment frequency count in map 2
		}

		std::vector<int> output;

		for (auto k : map2)
		{
			output.push_back(k.second);   // create vector of frequencies
		}

		++chisqMap[ChiSquare(output)];  // map the outputs of the chisquare  values should be cast to int
	}

	// ChiSquare should now have be a map in which the values follow chisquare distribution

	for (auto i : chisqMap)
	{
		std::cout << i.first << ": ";
		for (int k = 0; k < i.second; k++)
			std::cout << "-";
		std::cout << std::endl;
	}

	return 0;
}