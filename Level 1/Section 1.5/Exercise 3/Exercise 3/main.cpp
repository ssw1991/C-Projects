#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <numeric>
template<typename T>
double VectorMean(std::vector<T>& vector)
{ // Computes the mean of any numeric (non complex) type vector
	return std::accumulate(vector.begin(), vector.end(), 0.0) / vector.size();
}


template<typename T>
std::tuple<double,double> VectorSTD(std::vector<T>& vector)
{  // Returns a tuple (Standard deviation, mean deviation) of any numeric (non complex) vector
	double mean = std::accumulate(vector.begin(), vector.end(), 0.0) / vector.size();
	std::vector<double> diff(vector.size());
	// compute vector of absoulte deviation
	std::transform(vector.begin(), vector.end(), diff.begin(), [mean](double x) { return std::abs(x - mean); });
	// compute squared deviation
	double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	// sum absolute deviation
	double sum_dev = std::accumulate(diff.begin(), diff.end(), 0.0);
	return std::make_tuple(std::sqrt(sq_sum / vector.size()) , sum_dev / diff.size()) ;
}

template<typename T>
T VectorRange(std::vector<T>& vector)
{  // Computes the range of any numeric, non complex vector  
	auto range = std::minmax_element(vector.begin(), vector.end());
	return *range.second - *range.first;
}

template<typename T>
std::tuple<double, double, T, double, double> StatsProp(std::vector<T>& vector)
{ // returns a tuple of mean, mean deviation, range, standard deviation, and variance
	double st_dev, mean_dev;
	double mean = VectorMean<T>(vector);
	std::tie(st_dev, mean_dev) = VectorSTD<T>(vector);
	double range = VectorRange<T>(vector);
	return std::make_tuple(mean, mean_dev, range, st_dev, st_dev*st_dev);
}

template<typename T>
double VectorMedian(std::vector<T> v)
{ // Returns the median
	int N = v.size();
	
	if (N % 2 == 0) // For vectors of even length
		return (v[N/2 - 1] + v[N/2]) / 2.0;
	else // for vectors of odd length
		return v[(N / 2)];
}

template<typename T>
T VectorMode(std::vector<T> v)
{ // Per assignment, this assumes the vector is sorted.
	T mode= v[0];       // Assume mode is first number
	T curVal = v[0];    // Current value is first number
	int localFreq = 1;  // Local frequency is 1
	int MaxFreq = 1;    // Max frequency is 1

	for (int i = 1; i< v.size(); ++i) // start at second element
	{
		if (curVal != v[i]) //if current value changed, reset it and reset local frequency
		{
			curVal = v[i];  
			localFreq = 1;
		}
		else  // If it hasnt changed. increment local freq
		{
			localFreq++;
		}
		if (localFreq > MaxFreq) // if local freq is above max freq, reset max freq and mode 
		{ // This forces the assumption that mode is the lowest value 
			MaxFreq = localFreq;
			mode = v[i];
		}
	}
	return mode;
}


int main()
{
	std::vector<double> v;


	for (int i = 0; i < 10; i++)
	{
		v.push_back (i);
	}
	
	std::vector<int> v2{ 50,50,50,51,51,51,52,52, 52, 52};
	std::tuple<double, double, double, double, double> data = StatsProp<double>(v);

	// Should have used the TuplePrinter from earlier, but this was faster. 

	std::cout << std::get<0>(data) << std::endl;
	std::cout << std::get<1>(data) << std::endl;
	std::cout << std::get<2>(data) << std::endl;
	std::cout << std::get<3>(data) << std::endl;
	std::cout << std::get<4>(data) << std::endl;
	std::cout << VectorMedian<double>(v) << std::endl;
	std::cout << VectorMode<int>(v2);

}