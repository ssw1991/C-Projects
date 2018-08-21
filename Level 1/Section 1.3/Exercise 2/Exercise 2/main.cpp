#include <iostream>
#include <array>


class Shape 
{	
	public:  virtual void rotate(double d) = 0; 
};

class Circle : public Shape 
{ 
	public:  
		void rotate(double d) override 
		{ 
			std::cout << "c\n"; 
		} 
};

class Line : public Shape
{
	public:
		void rotate(double d) override 
		{ 
			std::cout << "l\n"; 
		}
};


class Valve 
{
	public:  
		void rotate(double d) 
		{ 
			std::cout << "v\n"; 
		} 
};


template<typename T>
void rotate(const double& factor, T& arg)
{
	arg.rotate(factor);
}

template<typename T, typename ... Types>
void rotate(const double& factor,  T& arg, Types& ... args)
{
	arg.rotate(factor);
	rotate(factor, args...);
}


int main()
{
	Circle circle;
	Line line;
	Valve valve;

	double factor = 2;

	rotate(factor, circle);
	rotate(factor, circle, line);
	rotate(factor, circle, valve);
	rotate(factor * 2, circle, valve, line);

	std::array<Shape*, 5>  shapeList{ &circle, &line, &circle, &circle, &line }; 
	double factor2 = 20.0; 
	for (auto& elem : shapeList) 
	{ 
		elem->rotate(factor2); 
	} // Cannot include valve because valve is not a shape, and therefor cannot be included in the array

	return 0;
}