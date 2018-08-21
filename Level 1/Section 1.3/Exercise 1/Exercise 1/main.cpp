

#include <iostream>
#include <vector>


template<typename T>
void Print(const T& arg)
{ // Function to print with no parameter pack
	std::cout << arg << std::endl;
	std::cout << "Termination Called";
}

template<typename T, typename ... Types>
void Print(const T& arg, const Types& ... args)
{
	std::cout << arg << ", ";
	Print(args...);  // calls itself if there is more than 1 arg, else calls other print.
}


int main() 
{
	Print(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	return 0;
};