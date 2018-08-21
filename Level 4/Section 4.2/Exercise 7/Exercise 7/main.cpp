#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>



void PrintVec(std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

std::vector<std::vector<int>> Superset(std::vector<int>& v)
{
	/*
	This algorithm was found on stack overflow.  Given some set {1,2,3},

	create set that contains a null set, and a set only containing the first element of the given set, this is output

	for each other element in the given set
		
		copy the output
		add the element from the original set to each set in the copy

		for each set in the copy, if it is not in the output add it to the output

		EX:: given {1,2,3}

		we begin with { {}, {1} }

		then we copy and add add next element for { {2}, {1,2} }

		we then add {2}, {1,2} to output because they werent present,  output is now { {}, {1}, {2}, {1,2} }

		We copy and add 3 again for { {3}, {1,3}, {2,3}, {1,2,3} }

		These all get added to output and that is the superset
	*/
	std::vector<std::vector<int>> output;
	output.push_back(std::vector<int>());
	std::sort(v.begin(), v.end());

	auto first_set = { v[0] };
	output.push_back( first_set );
	 // This output now contains a null set and a set containing the first value of the input vector

	for (int index =1; index < v.size(); index++)  // Now we will loop through all other elements of the input vector
	{
		auto i = v[index];
		auto copy_1 = output;   // create the copy
		for (auto j : copy_1)
		{ // For each set in the copy we will add the next element in the input vector
			auto f = [&j](auto vec) {return std::equal(vec.begin(), vec.end(), j.begin(), j.end()); }; //Checks if two ranges are equal

			j.push_back(i);
			if (std::none_of(output.begin(), output.end(), f))   // Evaluates true if j is not in current output  // Set union between output and the copy after modifying would be cleaner
				output.push_back(j);  // add j (from the copy) to output if it was not already in output
		}
	}

	return output;
}


int main()
{
	std::vector<int> v = { 1,-1,7,8,9,10 };
	std::vector<int> v2(v.size());

	std::copy_backward(v.begin(), v.end(), v2.rend());

	PrintVec(v2);

	std::rotate(v.begin(), v.begin() + 3, v.begin()+4);  
	PrintVec(v);

	v = { 1,-1,7,8,9,10 };
	std::rotate(v.begin(), v.begin() + 3, v.end());   // D;
	PrintVec(v);

	auto super = Superset(v);

	for (auto i : super)
		PrintVec(i);
	std::cout << super.size();  //Confirm its 64 because it includes the null set
}