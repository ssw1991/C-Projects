#include "Classes.hpp"
#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<Base> Factory()
{
	return std::make_shared<Derived>();
}
int main()
{

	std::vector<std::shared_ptr<Base>>  myvec;
	
	std::shared_ptr<Base> ptr = std::make_shared<Derived>();
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << ptr.use_count() << std::endl;
		myvec.push_back(ptr);
	}
	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<Base> p = Factory();
		myvec.push_back(p);
	}

	/*

	unique wont work 
	std::vector<std::unique_ptr<Base>>  myvec2;
	std::unique_ptr<Base> ptr2 = std::make_unique<Derived>();

	for (int i = 0; i < 10; i++)
	{
		
		myvec2.push_back(ptr2);
	}
	*/

	return 0;
}