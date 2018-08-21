#include <vector>
#include <iostream>



std::vector<bool> Intersection(const std::vector<bool>& v1, const std::vector<bool>& v2)
{
	// Considering with this implementation similar code would need to be written for every boolean operator
	// it is clear bitset is better

	if (v1.size() != v2.size())
		throw std::exception();  // Throw an exception if the vectors are different sizes
	std::vector<bool> v3;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == v2[i])
			v3.push_back(v1[i]); //if the index are the same push that value back (either 1, 0)
		else
			v3.push_back(0);  // if the index are different push back 0
	}

	return v3;

}

int main()
{
	std::vector<bool> bs1{ 1,0,1,0 };
	std::vector<bool> bs2{ 0,0,1,1 };

	/*
	This class does not support flip, reset, boolean operators.
	
	This class does not support construction from string
	
	*/
	std::vector<bool> intersection = Intersection(bs1, bs2);

	for (int i = 0; i < intersection.size(); i++)
		std::cout << intersection[i];   // Expect 0010

}