#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <functional>



int main()
{
	unsigned long a = 15278;
	unsigned long long b = 15728;
	std::string c = "01011100101";

	boost::dynamic_bitset<> bs1(12, a);
	boost::dynamic_bitset<> bs2(12, b);
	boost::dynamic_bitset<> bs3(c);
	boost::dynamic_bitset<> bs4(c, 3);

	std::cout << "Bs1: " << bs1 << " Bs2: " << bs2 << " Bs3: " << bs3 << " Bs4: " << bs4 << std::endl;

	//Set all bits

	bs1.set(1);

	// reset all bits

	bs2.reset();

	//Flip bits

	bs3.flip();

	//Access an element

	std::cout << "Accessing first element bs4: " << bs4[0] << std::endl;

	//Test if none of the bits are set

	std::cout << "bs2 test if no bits are set: " << bs2.none() << std::endl;

	//count set bits

	std::cout << "bs1 # set bits: " << bs1.count() << std::endl;

	std::cout << "Bs1: " << bs1.to_ulong() << " Bs2: " << bs2.to_ulong() << " Bs3: " << bs3.to_ulong() << " Bs4: " << bs4.to_ulong() << std::endl;
	

	// Test equality

	bs2.resize(12);
	bs4.resize(bs3.size());
	
	std::cout << "bs1 == bs2:  " << (bs1 == bs2) << std::endl;

	// Test if a bitset is a subset

	std::cout << "bs4 subset of bs3: " << bs4.is_subset_of(bs3) << std::endl;

	bs1.clear();
	bs1.push_back(0);
	bs1.push_back(1);
	bs1.push_back(0);
	bs1.push_back(1);

	bs2.clear();
	bs2.push_back(0);
	bs2.push_back(0);
	bs2.push_back(1);
	bs2.push_back(1);
	std::cout << bs2;

	

	bs1.flip(); // 0101
	bs2.flip(); // 0011

	std::cout << (bs1^bs2) << std::endl;  // XOR 0110
	std::cout << (bs1&bs2) << std::endl; // AND 0001
	std::cout << (bs1 | bs2) << std::endl; // OR 0111

	std::cout << (bs1 << 1) << std::endl; //Shift left 1010
	std::cout << (bs1 >> 1) << std::endl; // shift right 0010 

	bs1.append(1);  //000000000000000000000000000000010101
	std::cout << bs1<<std::endl;
	bs1.pop_back();
	std::cout << bs1<<std::endl;;

	std::cout << "first 1 in bs1: " << bs1.find_first() << std::endl;
	std::cout << "First 1 afer pos 3: " << bs1.find_next(2) << std::endl;
}
