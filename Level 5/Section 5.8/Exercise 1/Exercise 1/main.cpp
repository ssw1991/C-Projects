#include <vector>
#include <iostream>
#include <algorithm>

template<typename T> 
void Print(T t)
{
	for (auto i : t)
		std::cout << i << " ";
	std::cout << "\n\n";
}




int main()
{
	std::vector<int> vec{ 3,4,5,6,7,8,9,1,2,3,4 };

	std::make_heap(vec.begin(), vec.end());

	Print(vec);

	// the root is moved to the back,  the rest is rearranged as a heap
	std::pop_heap(vec.begin(), vec.end());  
	vec.pop_back();  // Removing the previous root
	Print(vec);

	// push heap will extend the range of what is considered a heap by one
	// and place the corresponging value in its location.  
	// We call push back first because there is not a value outside the range
	//of the heap yet
	vec.push_back(10);
	std::push_heap(vec.begin(), vec.end());
	Print(vec);

	std::sort_heap(vec.begin(), vec.end());
	Print(vec);

	std::cout << "Max: " << vec.back();


}