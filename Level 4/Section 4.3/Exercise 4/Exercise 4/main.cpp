#include <iostream>
#include <random>
#include <map>
#include <cmath>

double Distance(double& x, double& y)
{
	return std::pow((x*x + y * y), .5);
}


template <typename Dist, typename Eng>
void Pi(Dist& d, Dist& d2, Eng& e, Eng& e2, int nTrials)
{

	int count = 0;
	// Produce a number of variates from d
	for (int i = 0; i < nTrials; ++i)
	{
		auto x = d(e); auto y = d2(e2);
		if (Distance(x, y) < 1.0) { count++; }
	}
	std::cout << "Estimating Pi with " << nTrials << " trials: " << (1.0*count / nTrials)*4.0 << std::endl;

}



int main()
{
	std::mt19937 eng1(std::rand());
	std::mt19937 eng2(std::rand());
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	std::uniform_real_distribution<double> dist2(0.0, 1.0);

	Pi(dist, dist2, eng1, eng2, 10000);
	Pi(dist, dist2, eng1, eng2, 15000);
	Pi(dist, dist2, eng1, eng2, 20000);
	Pi(dist, dist2, eng1, eng2, 25000);
	Pi(dist, dist2, eng1, eng2, 30000);
	Pi(dist, dist2, eng1, eng2, 35000);
	Pi(dist, dist2, eng1, eng2, 1500000000);

}