#include <future>
#include <iostream>
#include <thread>
#include <chrono>
void PrintFuture(std::future<double>& f)
{ // thread function to get future data
	double val = f.get();
	std::cout << "Future Value is: " << val << std::endl;
}


int main()
{
	std::promise<double> p1;  //default constructor - empty shared state
	
	std::future<double> f1 = p1.get_future(); // associate future with shared state

	std::thread myThread(PrintFuture, std::ref(f1));
	std::this_thread::sleep_for(std::chrono::duration<int>(2)); // pause
	p1.set_value(15.0);
	std::promise<double> p2 = std::move(p1);  //p1 now invalid, constructed promise as move
	
	myThread.join();
	
}
