#include <vector>
#include <iostream>
#include <algorithm>

using Storage = std::vector<double>;

template <typename T>  
class Client 
{ // An example of Composition 
private:  

	Storage data; // typename mandatory

public: 
	Client(int n, const T& val) : data(n, val) {} 

	void print() const 
	{ 
		std::for_each(data.begin(), data.end(), [](const T& n) { std::cout << n << ","; });  
		std::cout << '\n'; 
	}
};

/*
template <typename T> 
struct Storage 
{   // Possible ADTs and their memory allocators  // 
	//typedef std::vector<T, CustomAllocator<T>> type;  
	typedef std::vector<T, std::allocator<T>> type; 
	//typedef std::list<T, std::allocator<T>> type;
};
*/

int main()
{
	

	Client<double> C(4, 4.0);

	C.print();

}