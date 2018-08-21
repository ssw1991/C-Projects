#include <boost/function.hpp>
#include <list>
#include <iostream>
#include <boost/signals2.hpp>


using namespace boost::signals2;
int main()
{
	// Create the signal
	signal<void(double&)> s1;
	signal<void(double&)> s2;
	signal<void(double&)> s3;
	signal<void(double&)> s4;


	double d = 0;

	// Create the attention list
	s1.connect([&d](double& x) {d = x; });  // initialize d (exterior)
	s1.connect(s2);
	s2.connect([](double& x) {if (x >= 4 | x <= 2) x = 3.0; }); // Check condition
	s2.connect(s3);
	s3.connect([](double& x) { x *= x; });
	s3.connect(s4);
	s4.connect([](double& x) {std::cout << x << std::endl; });

	// Trigger the event
	std::cout << "Give the value: "; double val; std::cin >> val;

	s1(val);
}