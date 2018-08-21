#include <iostream>
#include <ratio>


int main()
{
	std::ratio<1, 1000> r1;
	std::ratio<2, 354> r2;

	std::cout << "R1: " << r1.num << "/" << r1.den << " R2: " << r2.num << "/" << r2.den << std::endl;
	
	std::ratio_add<decltype(r1), decltype(r2)> r3;
	std::ratio_subtract<decltype(r1), decltype(r2)> r4;
	std::ratio_divide<decltype(r1), decltype(r2)> r5;
	std::ratio_multiply<decltype(r1), decltype(r2)> r6;

	std::cout << "Addition " << r3.num << "/" << r3.den << std::endl;
	std::cout << "Sub " << r4.num << "/" << r4.den << std::endl;
	std::cout << "Division " << r5.num << "/" << r5.den << std::endl;
	std::cout << "Mult " << r6.num << "/" << r6.den << std::endl;
	return 0;
}