#include <thread>
#include <iostream>
#include <functional>
#include "FunctionObjects.hpp"
#include <chrono>
#include <ctime>
#include <mutex>
#include <memory>
#include "TryLock.hpp"

std::mutex MTX;   // mutex for synronization
TryLock counter;

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
{ // Takes a function matchin the Iprint Interface and spawns a thread to time it

	// Exemplar code for system performance
	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	// Do something heavy here
	// Introduce delay to simulate a heavy algorithm
	std::thread t(f, s, count);
	join(t);
	end = std::chrono::system_clock::now();

	std::chrono::duration<double>
		elapsed_seconds = end - start;
	std::time_t end_time =
		std::chrono::system_clock::to_time_t(end);
	counter(MTX);
	std::cout << "Finished computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";
	MTX.unlock();
}

void Iprint(const std::string& s, int count)
{ // Function to print s, count # of times to terminal

	for (int i = 0; i <= count; i++)
	{
		counter(MTX); // Wait for Trylock to succeed
		std::cout << std::this_thread::get_id() << ": " << s << std::endl;
		MTX.unlock();
	}
}

auto lambdafunc = [&](const std::string& s, int count)	
{
	for (int i = 0; i <= count; i++)
	{
		counter(MTX); // Wait till try_lock succeeds
		std::cout << std::this_thread::get_id() << ": " << s << std::endl;
		MTX.unlock();
	}
};

std::mutex* FunctionObject::mtx = &MTX; // Assign static mutext in FO
int TryLock::count = 0;  // Assign static count in TryLock

int main()
{

	
	FunctionObject f;
	FunctionObject2 f2(&MTX);
	
	
	std::thread chronot(TestChrono, f, "FO", 1000);
	std::thread chronot2(TestChrono, &FunctionObject::Iprint, "Static Member Func", 1000);
	std::thread chronot3(TestChrono, std::bind(&FunctionObject2::Iprint, &f2, std::placeholders::_1, std::placeholders::_2), "Binded member function", 1000);
	std::thread chronot4(TestChrono, Iprint, "Free Function", 1000);
	std::thread chronot5(TestChrono, lambdafunc, "Stored Lambda", 1000);
	std::thread chronot6(TestChrono,
		[&](const std::string& s, int count)
		{
			for (int i = 0; i <= count; i++)
			{
				counter(MTX);  // wait for try_lock to succeed
				std::cout << std::this_thread::get_id() << ": " << s << std::endl;
				//MTX.unlock();  // Simulated DeadLock
			}
		}, "Lambda Func", 1000);
	join(chronot); join(chronot2); join(chronot3); join(chronot4); join(chronot5); join(chronot6);
	
	std::cout << TryLock::count << std::endl;
	
	return 0;
}

/*
With simple unlock / lock time was 2.77 seconds 
With try_lock time was 4.23 seconds 
program hangs when simulating a deadlock 

*/