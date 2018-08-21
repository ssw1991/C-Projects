#include <bitset>
#include <string>
#include <iostream>



int main()
{
	unsigned long a=15278;
	unsigned long long b = 15728;
	std::string c = "01011100101";

	std::bitset<12> bs1(a);
	std::bitset<12> bs2(b);
	std::bitset<12> bs3(c);
	std::bitset<9> bs4(c, 3);
		
	



	std::cout << "Bs1: " << bs1.to_string() << " Bs2: " << bs2.to_string() << " Bs3: " << bs3.to_string() << " Bs4: " << bs4.to_string() <<std::endl;

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

	std::cout << "bs1 # set bits: " << bs1.count() <<std::endl;

	std::cout << "Bs1: " << bs1.to_ulong() << " Bs2: " << bs2.to_ulong() << " Bs3: " << bs3.to_ulong() << " Bs4: " << bs4.to_ulong() << std::endl;
	std::cout << "Bs1: " << bs1.to_ullong() << " Bs2: " << bs2.to_ullong() << " Bs3: " << bs3.to_ullong() << " Bs4: " << bs4.to_ullong() << std::endl;
	
	// Test equality

	std::cout << "bs1 == bs2:  " << (bs1 == bs2);

}