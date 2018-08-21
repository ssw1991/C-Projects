#include <iostream>
#include <functional>


using VoidFunctionType = std::function<void(double)>;


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
};

class Circle : public Shape
{
private:
	VoidFunctionType m_f;
public:
	Circle (VoidFunctionType f): Shape(f)
	{
	}
	// No need for overriding the rotate, as it will call m_f.  We control 
	// which rotate is called by what function we pass the constructor 
};


void ShapeRotate(double d)
{
	std::cout << "S\n";
}

void CircleRotate(double d)
{
	std::cout << "C\n";
}
int main()
{
	
	Shape s(ShapeRotate);
	Circle c(CircleRotate);

	s.rotate(1);
	c.rotate(1);


	return 0;
}