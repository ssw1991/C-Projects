
#include <iostream>
#include <random>
#include <map>
#include <string>


// Key = bucket/value; Value = number of occurrences
std::map<long long, int> counter;



template <typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng e, int nTrials, const std::string& s)
{
	// Produce a number of variates from d
	for (int i = 1; i <= nTrials; ++i)
	{
		++counter[d(e)];
	}

	std::cout << s << std::endl;

	for (auto i : counter)
	{
		std::cout << i.first << ": ";
		for (int j = 0; j < i.second; ++j)
			std::cout << "-";
		std::cout << std::endl;
	}
	counter.clear();
}



int main()
{

	std::mt19937 eng1;


	double A = 0.0; double B = 1.0;

	std::geometric_distribution<int> dist1(.5);

	std::uniform_int_distribution<int> dist2(0.0, 10.0);
	std::poisson_distribution<int> dist3(5);



	GenerateRandomNumbers(dist1, eng1, 1000, "Geometric");
	GenerateRandomNumbers(dist2, eng1, 1000, "Uniform");
	GenerateRandomNumbers(dist3, eng1, 1000, "Poisson");


}

