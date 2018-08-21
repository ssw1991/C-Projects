#include <memory>
#include <iostream>

int main()
{

	std::shared_ptr<double> up = std::make_shared<double>(2.0);
	std::weak_ptr<double> wp;
	std::weak_ptr<double> wp1;
	std::shared_ptr<double> up1;

	std::cout << up.use_count() << std::endl;  // 1
	wp = up;
	std::cout << up.use_count() << std::endl; // 1 
	std::cout << "Check that wp is not empty: " << *wp.lock() << std::endl;  // 2 
	std::cout << up.use_count() << std::endl;  // 1
	
	up1 = wp.lock();
	std::cout << up.use_count() << std::endl;  // 2
	wp1 = wp; 

	std::cout << up.use_count() << std::endl;  // 2

	return 0;
}