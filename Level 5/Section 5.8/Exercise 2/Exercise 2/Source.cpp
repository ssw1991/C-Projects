#include <queue>
#include <iostream>
#include <functional>
#include <vector>
template<typename T>
void Print(T t)
{
	while (!t.empty())
	{
		std::cout << t.top() << " ";
		t.pop();
	}
	std::cout << "\n\n";
}

int main()
{
	std::vector<int> v{ 10,5,20,30,25,7,40 };
	std::priority_queue<int> q(std::less<int>(), v);
	Print(q);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q2(std::greater<int>(), v);
	Print(q2);

	auto cmp = [](int left, int right)-> bool {return (left > right); };

	std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp, v);
	Print(q3);

}