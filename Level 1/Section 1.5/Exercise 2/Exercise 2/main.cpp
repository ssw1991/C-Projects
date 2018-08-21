
#include <vector>
#include <tuple>
#include<algorithm>
#include <iostream>
#include <numeric>
/*

I recognize this is not the way the problem was intended to be solved, but 
I could not figure out how to unpack the Tuple, using a variadic approach.

Instead I modified the TuplePrinter Example to take a vector and unpack the
tuple into the vector

*/

template<typename Tuple,typename T, std::size_t N> 
struct TupleUnpack 
{ 
	static void Unpack(const Tuple& pack, std::vector<T>& v) 
	{ 
		TupleUnpack<Tuple,T, N - 1>::Unpack(pack , v); 
		v.push_back(std::get<N - 1>(pack)); 
	} 
};

template<typename Tuple, typename T> 
struct TupleUnpack<Tuple, T, 1> 
{ 
	static void Unpack(const Tuple& pack, std::vector<T>& v) 
	{ 
		v.push_back(std::get<0>(pack)); 
	} 
};

template <typename T, typename Tuple>  
struct Calculator
{
	Tuple _t;
	std::vector<T> v; 
	
	Calculator(Tuple t) : _t(t) 
	{
		TupleUnpack<Tuple, T, std::tuple_size<decltype(_t)>::value>::Unpack(_t, v);
	};

	T max()
	{
		return *std::max_element(v.begin(), v.end());
	}

	T sum()
	{
		return std::accumulate(v.begin(), v.end(), 0.0);
	}

	double average()
	{
		return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
	}

	
};  



int main()
{
	using DoubleTup = std::tuple<double, double, double>;

	DoubleTup a{ 1.0,2.0,3.0 };
	const int N = std::tuple_size <decltype(a)>::value;
	Calculator<double, DoubleTup> C(a);

	std::cout << C.max() << ", " << C.sum() << ", " << C.average();

}