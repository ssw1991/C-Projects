/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: wilsons
*
* Created on May 31, 2018, 11:46 AM
*/

#include <iostream>
#include <type_traits>
#include <string>
template<typename T>
void Print(T& t, std::true_type)
{ // Function to call if it is a pointer

	std::cout << *t << std::endl;
}

template<typename T>
void Print(T& t, std::false_type)
{ // Function to call if not a pointer

	if (std::is_scalar<T>())         // Ensures T is scalar
		std::cout << t << std::endl;
}

template<typename T>
void Print(T& t)
{ // Function called with only the variable 
	Print(t, std::is_pointer<T>());   // Call test if pointer to determine implementation
}

int main() {
	int* a;
	int b = 4;
	std::string s = "Hello";
	a = &b;

	Print(a);
	Print(b);
	Print(s);
	return 0;
}

