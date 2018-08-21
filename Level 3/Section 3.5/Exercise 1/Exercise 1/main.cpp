#include <iostream>
#include<queue>
#include<iostream>
#include <functional>

template <typename T, typename V, typename D>
void print(std::priority_queue<T, V, D> q)
{
	while (!q.empty())
	{ // While Q isnt empty, print top and remove
		std::cout << q.top() << ", ";
		q.pop();
	}
	std::cout << std::endl;
}

int main()
{
	// A 
	std::priority_queue<int> q1;

	q1.push(66); q1.push(22); q1.push(44);
	
	std::cout << q1.top() << std::endl;
	q1.push(11); q1.push(22); q1.push(33);

	print(q1);

	std::priority_queue<long long, std::deque<long long>, std::greater<long long> > q2; //Tried to use initializer list, but didnt accept ints
	q2.push(66); q2.push(22); q2.push(44); q2.push(11); q2.push(22); q2.push(33);
	
	print(q2);

	auto custom_compare = [](long long left, long long right) {return (left) > (right); };  //Bool  returns true if lhs is greater 

	std::priority_queue<long long, std::deque<long long>, decltype(custom_compare)> q3(custom_compare); //Tried to use initializer list, but didnt accept ints
	q3.push(66); q3.push(22); q3.push(44); q3.push(11); q3.push(22); q3.push(33);
	print(q3);

}