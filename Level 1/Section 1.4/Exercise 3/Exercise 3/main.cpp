#include <iostream>
#include <functional>

class C 
{ // Function object with extra member functions 

	private:   
		double _data; 
	public:  
		C(double data) : _data(data) {}

		double operator () (double factor) 
		{ 
			return _data + factor; 
		}

		double translate(double factor) 
		{ 
			return _data + factor; 
		}

		double translate2(double factor1, double factor2) 
		{ 
			return _data + factor1 + factor2; 
		}    
		
		static double Square(double x) 
		{ 
			return x * x; 
		}
};

template <typename T>  
using FunctionType = std::function<T(const T& t)>;



int main()
{
	C c(1);
	FunctionType<double> f = c.Square;
	std::cout << f(3) << std::endl;
	f = std::bind(&C::translate, c, std::placeholders::_1); //Arity 1, 
	std::cout << f(3.0) << std::endl; 
	f = std::bind(&C::translate2, c, std::placeholders::_1, 4); //Arity 1, 
	std::cout << f(3.0) << std::endl;
	f = std::bind(&C::operator(), c, std::placeholders::_1); //Arity 1, 
	std::cout << f(3.0) << std::endl;
}