#include <functional>
#include <iostream>


template <typename T>  
using FunctionType = std::function<T(const T& t)>;

using VoidFunctionType = std::function<void(double)>;

template <typename T>
class NextGenPolymorphism
{
private: 
	FunctionType<T> _func;
	T _fac;

public:
	NextGenPolymorphism(const FunctionType<T>& function, const T& factor) : _fac(factor)
	{
		_func = function;
	}

	T execute(double d)
	{
		return _func(d) * _fac;
	}

	void switchFunction(const FunctionType<T>& function)
	{
		_func = function;
	}

};

class Shape
{
private:
	VoidFunctionType m_f;

public:
	Shape(VoidFunctionType f)
	{
		m_f = f;
	}

	void rotate(double d)
	{
		m_f(d);
	};

	void switchFunc(const VoidFunctionType& function)
	{
		m_f = function;
	}
};


void rotate1(double)
{
	std::cout << "Calling Rotate 1\n";
}

void rotate2(double)
{
	std::cout << "Calling Rotate 2\n";
}

int main()
{
	auto square = [](double d) {return d * d; };
	auto expo = [](double d) {return std::exp(d); };

	NextGenPolymorphism<double> ng(square, 1.0); 
	std::cout << "Square: " << ng.execute(2.0) << '\n'; // 4 
	// square is not cool, switch to expo 
	ng.switchFunction(expo); 
	std::cout << "Exponential: " << ng.execute(5.0) << std::endl; // 148.413

	// Create a shape initalized with rotate 1
	Shape s(rotate1);

	//Test rotate

	s.rotate(1.0);

	// Change rotate function

	s.switchFunc(rotate2);
	s.rotate(2.0);
}