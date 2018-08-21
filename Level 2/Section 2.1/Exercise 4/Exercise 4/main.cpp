#include <type_traits>
#include <iostream>
#include "Shape.hpp"




int main()
{
	std::cout << std::boolalpha;

	// Programatically determine if Point has virtual destructor
	std::cout << "Point has virtual destructor: " << std::has_virtual_destructor<Point>::value << std::endl;


	// Programatically determine if point has default, copy, move constructors

	std::cout << "Default Constructible: " << std::is_default_constructible<Point>::value << std::endl;
	std::cout << "Copy Constructible: " << std::is_copy_constructible<Point>::value << std::endl;
	std::cout << "Move Constructible: " << std::is_copy_constructible<Point>::value << std::endl;



	// Programatically detemine if Point is copy assignable, move assignable
	std::cout << "Copy Assignable: " << std::is_copy_assignable<Point>::value << std::endl;
	std::cout << "Move Assignable: " << std::is_move_assignable<Point>::value << std::endl;


	/*

	Original output

	Default Constructible: true
	Copy Constructible: true
	Move Constructible: true
	Copy Assignable: true
	Move Assignable: true


	With deleted functions

	Point has virtual destructor: false
	Default Constructible: true
	Copy Constructible: false
	Move Constructible: false
	Copy Assignable: false
	Move Assignable: false

	Final Output

	Point has virtual destructor: false
	Default Constructible: true
	Copy Constructible: false
	Move Constructible: false
	Copy Assignable: false    - Why is this false?
	Move Assignable: true


	*/



	return 0;
}