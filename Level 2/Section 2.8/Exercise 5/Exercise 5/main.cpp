#include "BitSetMatrix.cpp"
#include <array>
#include <iostream>



int main()
{
	BitSetMatrix<4, 4> bm1;

	std::cout << bm1.any() << std::endl;
	bm1.flip();

	std::cout << "Count: " <<bm1.count() << std::endl;
	std::cout << "All: " << bm1.all() << std::endl;
	std::cout << "Any: " <<bm1.any() << std::endl;
	std::cout <<"bm1[3][3]: "<< bm1[3][3] << std::endl;
	bm1[3][3] = 0;
	std::cout <<"bm1[3][3]: " << bm1[3] << std::endl;
	std::cout << "All :" << bm1.all() << std::endl;
	/*
	bm1 is now <1111
				1111
				1111
				0111>
	*/
	std::bitset<4> a("1100");
	std::bitset<4> b("0000");
	std::bitset<4> c("1000");
	std::bitset<4> d("0100");

	std::array<std::bitset<4>, 4> abcd{ a,b,c,d };
	BitSetMatrix<4, 4> bm2(abcd);
	BitSetMatrix<4, 4> bm3 = (bm1^bm2);   // 0011.1111.0111.0011 count = 11
	BitSetMatrix<4, 4> bm4 = (bm1|bm2);   //  1111.1111.1111.0111 count = 15
	BitSetMatrix<4, 4> bm5 = (bm1&bm2);   //  1100.0000.1000.0100 count = 4

	std::cout << "bm3.count(): "<<bm3.count() << std::endl;
	std::cout << "bm4.count(): " << bm4.count() << std::endl;
	std::cout << "bm5.count(): " << bm5.count() << std::endl;


}

