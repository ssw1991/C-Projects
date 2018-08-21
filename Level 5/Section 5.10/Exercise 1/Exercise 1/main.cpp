#include <algorithm>
#include <functional>
#include <boost/numeric/ublas/vector.hpp>
#include <iostream>


namespace ublas = boost::numeric::ublas;

template<typename VecType>
void Print(VecType& v)
{
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{

	ublas::vector<double> v(5);  // Vector of size 5
	ublas::vector<double> v2(5);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i * .5;
		v2[i] = i * 1.5;
	}

	v(3) = 2.1; // Accessing using ()

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";   // Accessing using []
	
	std::cout << std::endl;

	v += v2; // + = v

	Print(v);

	v *= 2.5; 

	Print(v);

	v -= v2;

	Print(v);

	ublas::vector<double> v3(5);  // Empty vector with 5 elements

	std::transform(v.begin(), v.end(), v2.begin(), v3.begin(), std::multiplies<double>());
	Print(v3);

	ublas::vector<double> v4(100); // vector with 100 elements
	for (auto& i : v4)
		i = 5.0;
	Print(v4);




}