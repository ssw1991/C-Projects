#include <iostream>
#include <future>
#include <chrono>
#include <thread>


double longFunc()
{
	std::this_thread::sleep_for(std::chrono::duration<int>(3));  // create a pause
	return 4.0;
}

int main()
{
	std::cout << std::boolalpha;

	std::shared_future<int> f1;  // default constuctor
	std::cout << "Is f1 valid: " << f1.valid() << std::endl;  // valid works
	std::future<double> f2 = std::async(std::launch::async, longFunc);
	std::shared_future<double> f3 = f2.share() ;      //f2 now empty

	std::cout << "Is f2 valid: " << f2.valid() << std::endl;  // valid works
	std::shared_future<double> f4 = f3;

	std::cout << "f3: " << f3.get() << ": f4: " << f4.get() << ": f3 again: " << f3.get() << std::endl;

	std::shared_future<double> f5 = std::move(f4); // Transfer shared state
	std::cout << "f5: " << f5.get() << "Is f4 valid: " << f4.valid() << std::endl;

	std::shared_future<double> f6 = std::async(std::launch::async, longFunc);
	auto status = f6.wait_for(std::chrono::duration<int>(1));  // force timeout
	if (status == std::future_status::timeout)
		std::cout << "timeout" << std::endl;   

	auto target_time = std::chrono::system_clock::now() + std::chrono::duration<int>(4); // time point for wait_until
	std::shared_future<double> f7 = std::async(std::launch::async, longFunc); // start another long func

	do { // print status when ready, guaranteed entry
		if (status == std::future_status::ready) 
			std::cout << "ready!\n";
	   } while (status != std::future_status::ready);
}