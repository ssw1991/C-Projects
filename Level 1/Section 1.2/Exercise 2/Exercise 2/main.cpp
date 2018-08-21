
#include <iostream>
#include <string>
#include <vector>
#include <chrono>



class Test
{
	/*
	 Class to test copyswap and move swap functions and count the constructor calls

	 Class is not complete, only has the functions required too count constructor calls 
	 and test the move
	*/
	public:
		std::string m_data;
		static int count; // To count constructor calls

		Test() : m_data("String")
		{
			std::cout << "C0" << std::endl;
			Test::count++;
		};

		Test(std::string s) : m_data(s)
		{
			std::cout << "C1" << std::endl;
			Test::count++;
		};

		Test(Test& source) : m_data(source.m_data)
		{
			std::cout << "C3" << std::endl;
			Test::count++;
		}

		Test(Test&& source)
		{
			m_data = std::move(source.m_data);
		};

		Test& operator = (Test&& source)
		{
			m_data = std::move(source.m_data);
			return *this;
		};

		Test& operator = (const Test& source)
		{
			
				if (this == &source)  return *this;   // Exit if same object. 
				// Delete old data, allocate new and copy data. 

				m_data=source.m_data; 
				return *this;
			
		}
			
};

int Test::count = 0;

template < typename T >  
void SwapCopyStyle(T& a, T& b) 
{ // Swap a and b in copying way; temporary object needed 

	T tmp(a); // Copy constructor 
	a = b;  // Copy all elements from b to a   Had to create an explicit = overload
	b = tmp; // Copy all elements from tmp to b 
}

template < typename T >
void SwapMoveStyle(T& a, T& b)
{ // Swap a and b in copying way; temporary object needed 

	T tmp = std::move(a); // moves  
	a = std::move(b);  // Move elements from b to a
	b = std::move(tmp); //move elements from tmp to b 
}



int main()
{
	std::string target = "I am a the target";
	std::string source = "I am the source";

	std::cout << "Before Move:\nTarget: " << target << "\nSource: " << source << std::endl;

	source = std::move(target);
	std::cout << "After Move:\nTarget: " << target << "\nSource: " << source << std::endl;


	std::vector<double> v1;
	std::vector<double> v2;
	std::vector<double> v3;
	std::vector<double> v4;

	// Fill vectors 1 and 4

	for (int i = 0; i < 1000000; i++)
	{
		v1.push_back(i / 10.0);
		v4.push_back(i / 20.0);
	}

	// Time the copy swap

	auto start = std::chrono::high_resolution_clock::now();
	v2 = v1;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = end - start;

	std::cout << "Duration for copy is: " << duration.count() << std::endl;

	// Time the move swap
	start = std::chrono::high_resolution_clock::now();
	v3 = std::move(v1);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	std::cout << "Duration for move is: " << duration.count() << std::endl;

	Test a("hi");  // Calls c1
	Test b("by");  // Calls c1
	std::cout << "Current Constructor Call: " << Test::count << std::endl;
	Test::count = 0;
	SwapCopyStyle(a, b);  //Calls C3, copy constructor 
	std::cout << "New calls to constructor because of swap: " << Test::count << std::endl;
	Test::count = 0;

	SwapMoveStyle(a, b);

	std::cout << "New calls to constructor because of swap using move: " << Test::count << std::endl;

	start = std::chrono::high_resolution_clock::now();
	SwapCopyStyle(v3, v4);
	end = std::chrono::high_resolution_clock::now();
	auto duration1 = end - start;
	std::cout << "Duration for Vector Swap copystyle is: " << duration1.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	SwapMoveStyle(v3, v4);
	end = std::chrono::high_resolution_clock::now();
	auto duration2 = end - start;
	std::cout << "Duration for Vector Swap move style is: " << duration2.count() <<
		"\nperformance increase is: " << static_cast<double>((duration1.count() - duration2.count())) / duration1.count() << std::endl;

}