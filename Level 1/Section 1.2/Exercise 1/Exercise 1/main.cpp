/*
 * File:   main.cpp
 * Author: wilsons
 *
 * Created on May 10, 2018, 6:29 PM
 */

#include <iostream>
#include "C.hpp"

using namespace std;

/*
 * 
 */
int main() {
    double getTest;
    double sizeTest;
    
    C my_c(1);

    C my_c2(1);
    //my_c2 = my_c; 
    // C my_c3(my_c2); can no longer call because this function was deleted, and declared explicitly
	// C my_c3 = my_c2;  can no longer call because this function ws deleted
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
    return 0;
}

