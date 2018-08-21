#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


/*

To make a vector into a set, I will first sort, then remove duplicates, then remove vals < 2

*/

bool UserLessThan(int v1, int v2)
{
	return v1 <= v2;
}


template <typename T>
void PrintVec(std::vector<T>& v)
{
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


auto lambdaFunc = [](int i) {return (i <= 2); };

std::vector<int> MakeSet(std::vector<int> v, int threshold, std::function<bool(int, int)> f)
{
	std::sort(v.begin(), v.end());
	
	auto last = std::unique(v.begin(), v.end());   // Returns a pointer to last element after removal
	v.erase(last, v.end());


	last = std::remove_if(v.begin(), v.end(), std::bind(f, std::placeholders::_1, threshold));
	v.erase(last, v.end());

	return v;
}



int main()
{
	std::vector<int> v = { 1,2,1,4,5,5,-1 };

	std::vector<int> v1 = MakeSet(v, 2, UserLessThan);
	std::vector<int> v2 = MakeSet(v, 2, [](int i1, int i2) {return (i1 <= i2); });
	std::vector<int> v3 = MakeSet(v, 2, std::less_equal<int>());   // This one is the easiest
	
	
	PrintVec<int>(v);
	PrintVec<int>(v1);
	PrintVec<int>(v2);
	PrintVec<int>(v3);
	
}