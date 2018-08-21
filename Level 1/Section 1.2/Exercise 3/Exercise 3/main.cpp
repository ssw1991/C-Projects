/*
 * File:   main.cpp
 * Author: wilsons
 *
 * Created on May 10, 2018, 6:29 PM
 */

#include <iostream>
#include "C.hpp"

using namespace std;


C&& CRvalue()
{
	return C(1);
}

/*
 * 
 */
int main() {
    double getTest;
    double sizeTest;
    
	C my_c(1);
    C my_c2(1);
	C my_c3;

	for (int i = 0; i < my_c3.Size(); i++)
	{
		my_c3[i] = i;
	};

    my_c3.ScalerMult(5);
    my_c3.Print();
    
    my_c3[4] = 6.0;
    getTest = my_c3.GetElement(4);
    sizeTest = my_c3.Size();
    my_c3.Print();

	C my_c4 = std::move(my_c3); // Using lvalue as source of move operation results in the move copy being called
	C my_c5;
	my_c5 = CRvalue();   // using Rvalue results in move assignment being called
	C my_c6 = CRvalue(); //Results in move copy being called.

    return 0;
}

