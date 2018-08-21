#include <boost/function.hpp>
#include <list>
#include <iostream>
#include <boost/signals2.hpp>

void CPrint(double x)
{
		std::cout << "C function: " << x << std::endl;		
}

struct Print
{
		void operator() (double x)
	{
		std::cout << "I am a printer " << x << std::endl;
	}
};

struct MathsWhiz
{
	double m_x;

	MathsWhiz(double x) : m_x(x)
	{};
	void operator ()(double x)
	{
		std::cout << "I am a mathwhiz, x time "<< m_x <<" is " << (m_x*x) << std::endl;
	}
};

struct DataBase
{
	void operator()(double x)
	{
		std::cout << "This is the database: " << x << std::endl;
	}
};

using namespace boost::signals2;
int main()
{
	// Create the signal
	signal<void(double)> s;

	
	Print myPrint;

	MathsWhiz myMaths(10.0);
	DataBase myDatabase;

	// Create the attention list
	s.connect(myPrint);
	s.connect(myMaths);
	s.connect(myDatabase);
	s.connect(&CPrint);

	// Trigger the event
	std::cout << "Give the value: "; double val; std::cin >> val;

	s(val);
}