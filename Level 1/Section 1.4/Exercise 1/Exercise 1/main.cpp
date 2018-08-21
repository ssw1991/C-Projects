

#include <functional>
#include <iostream>


template <typename T>
using FunctionType = std::function<T(const T& t)>;




double squared(const double& x)
{//Free Function
	return x * x;
}

template <typename T>  
void print(const FunctionType<T>& f, T t) 
{ 
	std::cout << f(t) << '\n';
}

class Squared
{
	public:
		double operator () (const double& x)
		{
			return x * x;
		}
};


int main()
{
	FunctionType<double> f;
	auto storedLambda = [](double x) {return x * x; };
	Squared s;
	f = s;
	print(f, 4.0);
	f = squared;
	print(f, 4.0);
	f = storedLambda;
	print(f, 4.0);
	return 0;
}
