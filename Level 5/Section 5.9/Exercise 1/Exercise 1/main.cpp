#include <boost/signals2.hpp>
#include<iostream>
#include <functional>




using namespace boost::signals2;

void PrintWorld()
{
	std::cout << "World!!";
}  // Free Function for signal

auto pHello = [](){ std::cout << "Hello "; };  // Lambda for signal

struct fromSignal
{
	void operator() ()
	{
		std::cout << " from signals" << std::endl;
	}
};


struct MyStruct
{
	double val;
	MyStruct(double v) 
	{ val = v; }
	void modify(double newValue)
	{
		val = newValue;
		std::cout << "A third slot " << val << std::endl;
	}
};
int main() 
{
	signal<void()> s;
	s.connect(pHello);
	s.connect(PrintWorld);
	s.connect(fromSignal());

	s();  // All connections made ... should execute in order
	
	MyStruct m(4);
	
	s.connect(std::bind(&MyStruct::modify, &m, 3));
	s();  // All connection still on
	s.disconnect(PrintWorld);
	s();

	// Define potential emitters
	boost::signals2::signal<void()> signalA;
	boost::signals2::signal<void()> signalB;
	boost::signals2::signal<void()> signalC;
	boost::signals2::signal<void()> signalD;

	// Define slots
	auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; };
	auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; };
	auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; };
	auto slotD2 = []() {std::cout << "Slot D2 called by D\n " << std::endl; };


	signalA.connect(signalB);
	signalB.connect(signalC);
	signalC.connect(signalD);
	signalB.connect(slotB);
	signalC.connect(slotC);
	signalD.connect(slotD1);
	signalD.connect(slotD2);

	signalA();  // Will call signal B which calls signal C then slot B
				// Then signal C calls signal D then slotC
				// Then signal D calls d1 and d2

}