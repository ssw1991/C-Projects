#include <thread>
#include <iostream>
#include <functional>
#include "FunctionObjects.hpp"
#include <chrono>
#include <ctime>


void join(std::thread &t)
{// joins thread if joinable, exception safe
 // Why wouldn't we just call if(t.joinable){t.join()}?
	try
	{
		t.join();
	}

	catch (std::system_error &e) {}
}


void TestChrono(std::function<void(const std::string&, int)> f, const std::string& s, int count)
{
	// Exemplar code for system performance
	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	// Do something heavy here
	// Introduce delay to simulate a heavy algorithm
	std::thread t (f, s, count);
	join(t);
	end = std::chrono::system_clock::now();

	std::chrono::duration<double>
		elapsed_seconds = end - start;
	std::time_t end_time =
		std::chrono::system_clock::to_time_t(end);
	
	std::cout << "Finished computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";
}

void Iprint(const std::string& s, int count)
{ // Function to print s, count # of times to terminal

	for (int i = 0; i <= count; i++)
		std::cout << std::this_thread::get_id() << ": " << s << std::endl;
}

auto lambdafunc = [&](const std::string& s, int count)	
					{
						for (int i = 0; i <= count; i++)
							std::cout << std::this_thread::get_id() << ": " << s << std::endl;
					};

int main()
{
	FunctionObject f;
	FunctionObject2 f2;
	int val = 20;
	std::thread t(f, "Fo", val);   // Function object thread
	std::thread t2(&FunctionObject::Iprint, "Static Member Func", val);  // Thread with Static Member Function
	t2.detach();
	std::thread t3(std::bind(&FunctionObject2::Iprint, &f2, "Binded member function", val));   //Thread using bind on a member function
	std::thread t4(Iprint, "Free Function", val);	// Thread using Free Function									
	std::thread t5(lambdafunc, "Stored Lambda", val); //  Thread using Stored Lambda
	std::thread t6([&](const std::string& s, int count) 
				{
					for (int i = 0; i <= count; i++)
						std::cout << std::this_thread::get_id() << ": " << s << std::endl;
				} , "Lambda Func", val);  // Thread using Lambda
	join(t); join(t2); join(t3); join(t4); join(t5); join(t6);  // t2 cant be joined because it is detached
	
	
	// Using Test Chrono, in a way that it will call each thread serially to time that thread;
	TestChrono(f, "FO", 1000);
	TestChrono(&FunctionObject::Iprint, "Static Member Func", 1000);
	TestChrono(std::bind(&FunctionObject2::Iprint, &f2, std::placeholders::_1, std::placeholders::_2), "Binded member function", 1000);
	TestChrono(Iprint, "Free Function", 1000);
	TestChrono(lambdafunc, "Stored Lambda", 1000);
	TestChrono([&](const std::string& s, int count)
	{
		for (int i = 0; i <= count; i++)
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
	}, "Lambda Func", 1000);
	
	
	//  Using Test Chrono to time all the threads working together,
	// However, in this case each thread will spawn another thread.
	std::thread chronot(TestChrono, f, "FO", 1000);
	std::thread chronot2(TestChrono, &FunctionObject::Iprint, "Static Member Func", 1000);
	std::thread chronot3(TestChrono, std::bind(&FunctionObject2::Iprint, &f2, std::placeholders::_1, std::placeholders::_2), "Binded member function", 1000);
	std::thread chronot4(TestChrono, Iprint, "Free Function", 1000);
	std::thread chronot5(TestChrono, lambdafunc, "Stored Lambda", 1000);
	std::thread chronot6(TestChrono, 
							[&](const std::string& s, int count)
						{
							for (int i = 0; i <= count; i++)
								std::cout << std::this_thread::get_id() << ": " << s << std::endl;
						}, "Lambda Func", 1000);
	join(chronot); join(chronot2); join(chronot3); join(chronot4); join(chronot5); join(chronot6);
	

	/*
	Answer to Final Question:

	When the threads are being ran simultenously, there is no lock on access to the console,
	therefore sometimes there output interferes with eachother.  For Example t1 might insert an endl, while t2 is writing.
	*/
	return 0;
}