#include <iostream>
#include "Proposition.hpp"
#include <bitset>



int main()
{
	std::bitset<1> b(1);

	Proposition T1(b);      // True Bitset Constructor
	Proposition F1(0);		// False Integer Constructor
	Proposition T2(true);	// True Boolean Constructor
	Proposition F2(F1);		// False Copy Constructor


	std::cout << std::boolalpha;
	std::cout << !!T1 << std::endl;   // Test Negation (double negation)
	std::cout << !!F1 << std::endl;
	std::cout << !!T2 << std::endl;
	std::cout << !!F2 << std::endl;   // Ensure all objects constructed Appropriatly
	
	std::cout << (T1 == T2) << ", " << (T1 != T2) << ", " << (T1 == F1) << ", " << (T1 != F1)
		<< ", " << (F1 == F2) << ", " << (F1 != F2) << std::endl;   // Check equality and inequality 
	
	std::cout << (T1 & T2) << ", " << (T1 & F1) << ", " << (F1 & F2) << std::endl; // Check &
	std::cout << (T1 | T2) << ", " << (T1 | F1) << ", " << (F1 | F2) << std::endl; // Check |
	std::cout << (T1 ^ T2) << ", " << (T1 ^ F1) << ", " << (F1 ^ F2) << std::endl; // Check &


	// Check Demoragans Law

	std::cout << "Demorgans Law: " << (!(T1 | F1) == (!T1 & !F1)) << std::endl;
	std::cout << "Demorgans Law: " << (!(T1 & F1) == (!T1 | !F1)) << std::endl;

	//Distributive Law

	std::cout << "Distributive Law: " << ( T1 & (T2 | F1) == ( (T1&T2) | (T1&F1) ) ) << std::endl;
	std::cout << "Distributive Law: " << ( T1 | (T2 & F1) == ( (T1|T2) & (T1|F1) ) ) << std::endl;
	
	// Check if tautological
	// Checks based on these truth tables http://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html
	// Will negates false, so all checks should be true

	// OR
	std::cout << (T1 & T2) << std::endl;
	std::cout << !(T1 & F1) << std::endl;
	std::cout << !(F1 & T1) << std::endl;
	std::cout << !(F2 & F1) << std::endl;

	// OR

	std::cout << (T1 | T2) << std::endl;
	std::cout << (T1 | F1) << std::endl;
	std::cout << (F1 | T1) << std::endl;
	std::cout << !(F2 | F1) << std::endl;


	// Implication 

	std::cout << (T1 % T2) << std::endl;
	std::cout << !(T1 % F1) << std::endl;
	std::cout << (F1 % T1) << std::endl;
	std::cout << (F2 % F1) << std::endl;

	// Double implication 

	std::cout << (T1 %= T2) << std::endl;
	std::cout << !(T1 %= F1) << std::endl;
	std::cout << !(F1 %= T1) << std::endl;
	std::cout << (F2 %= F1) << std::endl;

	return 0;
}