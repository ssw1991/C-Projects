#include <iostream>
#include <type_traits>
#include <string>
#include "Header.h"
#include <memory>
template<typename T>
std::string Type(T& obj)
{
	if (std::is_pointer<T>::value) // Check if T is pointer (obj is passed by reference and is a reference)
		return "Pointer";
	else if (std::is_lvalue_reference<decltype(obj)>::value)
		return "Lvalue Reference";
}

std::string Type(std::nullptr_t nullp)
{ // Over load becaus std::nullptr cant be passed by reference
	return "Null Pointer";
}


template<typename T>
std::string Type(T&& obj)
{ // Overload to accept Rvalue Reference
	if (std::is_rvalue_reference<decltype(obj)>::value)
		return "Rvalue Reference";
}

template<typename T>
std::string FuncObj(T& obj)
{
	if (!std::is_member_pointer<T>::value)
		return "Not a pointer to a member function or object";
	if (std::is_member_function_pointer<T>::value)
		return "Pointer to member function";
	if (std::is_member_object_pointer<T>::value)
		return "Pointer to member object";
}

double mutableRvalue()
{
	return 3.14;
}

int main()
{
	int b = 3;
	int *a = &b;
	auto sp = std::make_shared<int>(12);   // Shared Pointer
	auto rp = sp.get();                    // Raw Pointer

	Test myobj;

	auto objPointer = &Test::val;
	auto funcPointer = &Test::getVal;

	std::cout << Type(nullptr) << std::endl;            // Null Pointer
	std::cout << Type(a) << std::endl;					// Pointer		
	std::cout << Type(b) << std::endl;					// Lvalue Reference
	std::cout << Type(mutableRvalue()) << std::endl;    // RValue Reference
	std::cout << FuncObj(objPointer) << std::endl;		// Pointer to Member Object
	std::cout << FuncObj(funcPointer) << std::endl;		// Pointer to Member Function
	std::cout << Type(sp) << std::endl;					// Shared pointer not a pointer
	std::cout << Type(rp) << std::endl;					// Pointer
}



