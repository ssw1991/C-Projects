#include <iostream>
#include <random>

template <typename Dist, typename Eng>
void PrintRandom(Dist d, Eng e, int nTrials)
{
	// Produce a number of variates from d
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << d(e) << ", ";
	}
	std::cout << "end\n\n";
}



int main()
{
	std::linear_congruential_engine<uint_fast32_t, 48271, 0, 2147483647> eng1;
	std::mt19937 eng2;
	std::mt19937_64 eng3;

	double A = 0.0; double B = 1.0;

	std::uniform_real_distribution<double> dist1(A, B);

	std::normal_distribution<double> dist2(0.0, 1.0);
	std::chi_squared_distribution<double> dist3(5);
	std::cauchy_distribution<double> dist4(1.0, 1.0);
	std::bernoulli_distribution dist5(.5);

	PrintRandom(dist1, eng1, 10);
	PrintRandom(dist2, eng2, 10);
	PrintRandom(dist3, eng3, 10);
	PrintRandom(dist4, eng1, 10);
	PrintRandom(dist5, eng1, 10);

}