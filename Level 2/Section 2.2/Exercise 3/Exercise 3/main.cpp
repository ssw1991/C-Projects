#include <type_traits>
#include <array>
#include <complex>
#include <iostream>
#include <vector>

template<typename T>
void ToggleSign(T& val)
{
	toggleImpl(val, std::is_signed<T>());
}

template<typename T>
void toggleImpl(T& val, std::true_type)
{
	std::cout << std::boolalpha;
	typedef std::make_unsigned<T>::type myType;
	std::cout << "Is the type unsigned: " << std::is_unsigned<myType>::value << std::endl;
}

template<typename T>
void toggleImpl(T& val, std::false_type)
{
	std::cout << std::boolalpha;
	typedef std::make_signed<T>::type myType;
	std::cout << "Is the type signed: " << std::is_signed<myType>::value << std::endl;
}

template<typename T>
void Toggleconst(const T& val)
{
	std::cout << std::boolalpha;
	typedef std::remove_const<T>::type myType;
	std::cout << "Is the type const: " << std::is_const<myType>::value << std::endl;
}

template<typename T>
void Toggleconst(T& val)
{
	std::cout << std::boolalpha;
	typedef std::add_const<T>::type myType;
	std::cout << "Is the type const: " << std::is_const<myType>::value << std::endl;
}

template<typename T>
void TogglePointer(T& val)
{
	togglePointer(val, std::is_pointer<T>());
}

template<typename T>
void togglePointer(T& val, std::true_type)
{
	std::cout << std::boolalpha;
	typedef std::remove_pointer<T>::type myType;
	std::cout << "Is the type a Pointer: " << std::is_pointer<myType>::value << std::endl;
}

template<typename T>
void togglePointer(T& val, std::false_type)
{
	std::cout << std::boolalpha;
	typedef std::add_pointer<T>::type myType;
	std::cout << "Is the type a Pointer: " << std::is_pointer<myType>::value << std::endl;
}

template<typename T>
void ToggleVol(T& val)
{
	togglevol(val, std::is_volatile<T>());
}

template<typename T>
void togglevol(T& val, std::true_type)
{
	std::cout << std::boolalpha;
	typedef std::remove_volatile<T>::type myType;
	std::cout << "Is the type a volatile: " << std::is_volatile<myType>::value << std::endl;
}

template<typename T>
void togglevol(T& val, std::false_type)
{
	std::cout << std::boolalpha;
	typedef std::add_volatile<T>::type myType;
	std::cout << "Is the type a volatile: " << std::is_volatile<myType>::value << std::endl;
}
int main()
{
	int i1;
	int* ptr;
	unsigned int i2;
	const int i3(4);
	volatile int i5;

	ToggleSign(i1);
	ToggleSign(i2);
	Toggleconst(i3);
	Toggleconst(i1); 
	TogglePointer(i1);
	TogglePointer(ptr);
	ToggleVol(i1);
	ToggleVol(i5);
}