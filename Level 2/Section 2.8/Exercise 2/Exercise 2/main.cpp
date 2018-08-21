#include <iostream>
#include <bitset>
#include <string>
#include <functional>

int main()
{
	std::bitset<4> bs1("1010");
	std::bitset<4> bs2("1100");

	bs1.flip(); // 0101
	bs2.flip(); // 0011

	std::cout << (bs1^bs2) <<std::endl;  // XOR 0110
	std::cout << (bs1&bs2) << std::endl; // AND 0001
	std::cout << (bs1|bs2) << std::endl; // OR 0111

	std::cout << (bs1 << 1) << std::endl; //Shift left 1010
	std::cout << (bs1 >> 1) << std::endl; // shift right 0010 

	std::hash<std::bitset<4>> hash_fun;
	std::cout << hash_fun(bs1) << std::endl; 
	std::cout << hash_fun(bs2) << std::endl; 
}