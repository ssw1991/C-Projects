#include <iostream>
#include <random>
#include <bitset>
#include <chrono>


template<int N>
double BitRatio()
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::mt19937 eng1(seed);
	std::independent_bits_engine<std::mt19937, N, uint_fast64_t> g1(eng1);
	
	return(std::bitset<N>(g1()).count());
}

int main()
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::mt19937 eng1(seed);

	std::independent_bits_engine<std::mt19937, 2, uint_fast64_t> g1(eng1);
	auto val = g1();
	auto b1 = std::bitset<2>(val);


	std::cout << "as int: " << val << " as bitset: " << b1 << std::endl;

	//  Initializing counts to 0 to count the frequency of 1,0 in the bitset
	double count2 = 0.0;
	double count8 = 0.0;
	double count16 = 0.0;
	double count64 = 0.0;

	for (int i = 0; i < 100; ++i)
	{
		count2 += BitRatio<2>();
		count8 += BitRatio<8>();
		count16 += BitRatio<16>();
		count64 += BitRatio<64>();
	}

	// Compute num of bits set / total num bits

	double score2 = count2 / (2.0 * 100);
	double score8 = count8 / (8.0 * 100);
	double score16 = count16 / (16.0 * 100);
	double score64 = count64 / (64.0 * 100);

	std::cout << "Score at 2: " << score2 << " Score at 8: " << score8 << 
		" Score at 16: " << score16 << " Score at 64: " << score64;

}

