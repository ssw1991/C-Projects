#include <iostream>
#include <vector>
#include <random>


void PrintVec(std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}



int main()
{
	std::vector<int> myvec = { 1,2,3,4,5,6,7,8,9,10 };

	auto myrand1 = [](int i) {return std::rand() % i; };
	std::random_shuffle(myvec.begin(), myvec.end(), myrand1);
	PrintVec(myvec);

	std::mt19937 gen1;
	std::default_random_engine gen2;
	std::linear_congruential_engine<std::uint_fast32_t, 48271, 0, 2147483647> gen3;

	auto myrand2 = [&gen1](int i) {return gen1() % i; };
	auto myrand3 = [&gen2](int i) {return gen2() % i; };
	auto myrand4 = [&gen3](int i) {return gen3() % i; };


	std::random_shuffle(myvec.begin(), myvec.end(), myrand2);
	PrintVec(myvec);


	std::random_shuffle(myvec.begin(), myvec.end(), myrand3);
	PrintVec(myvec);

	std::random_shuffle(myvec.begin(), myvec.end(), myrand4);
	PrintVec(myvec);
}