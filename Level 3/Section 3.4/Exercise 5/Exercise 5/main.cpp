#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <omp.h>
#include <chrono>
#include <ctime>

std::atomic<int> SUM = 0;
std::timed_mutex mtx;

template<typename T>
void TestChrono(T& fullyboundFunction)
{ // Takes a function matchin the Iprint Interface and spawns a thread to time it

  // Exemplar code for system performance
	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	std::thread t(fullyboundFunction);
	t.join();
	end = std::chrono::system_clock::now();
	std::chrono::duration<double>
		elapsed_seconds = end - start;
	std::time_t end_time =
		std::chrono::system_clock::to_time_t(end);
	
	std::cout << "Finished computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

}


long ParallelSum(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	auto len = end - beg;
	if (len < 1000)
		return std::accumulate(beg, end, 0);

	std::vector<int>::iterator mid = beg + len / 2;
	auto handle = std::async(std::launch::async,
		ParallelSum, mid, end);
	int sum = ParallelSum(beg, mid);
	return sum + handle.get();
}

long ParallelMult(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	auto len = end - beg;
	if (len < 1000)
		return std::accumulate(beg, end, 1, std::multiplies<double>());

	std::vector<int>::iterator mid = beg + len / 2;
	auto handle = std::async(std::launch::async,
		ParallelSum, mid, end);
	int sum = ParallelSum(beg, mid);
	return sum + handle.get();
}


void ThreadSum(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	auto len = end - beg;
	if (len < 1000)
	{
		while (! mtx.try_lock()) {};       //Try until lock is made
		SUM += std::accumulate(beg, end, 0);
		mtx.unlock();
	}
	std::vector<int>::iterator mid = beg + len / 2;
	std::thread t1 (ThreadSum, mid, end);
	std::thread t2 (ThreadSum,beg, end);
	t1.join();
	t2.join();
}

#pragma omp parallel num_threads(8);
#pragma omp parallel for reduction (+:sumParallel)
long ParallelSum2(std::vector<int>& v)
{
long sumParallel = 0;
for (long i = 0; i < v.size(); ++i)
{
sumParallel += v[i];
}
return sumParallel;
}

int main()
{

	/*
	For some of the template functions bind couldnt recognize which version to use
	so I wrapped the timeing code around execution
	*/
	std::vector<int> v(10000, 1);
	int sum;
	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	std::chrono::duration<double>
		elapsed_seconds;

	start = std::chrono::system_clock::now();
	sum = std::accumulate(v.begin(), v.end(), 0);   // Standard Accumulate
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;

	std::cout << "Finished computation for accumulate at "
		<< "elapsed time: "
		<< elapsed_seconds.count() <<" answer is : " << sum<< "s\n";


	start = std::chrono::system_clock::now();
	sum = ParallelSum2( v);                    // Open MP
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;

	std::cout << "Finished computation for accumulate at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << " answer is : " << sum << "s\n";

	auto f2 = std::bind(ParallelSum, v.begin(), v.end());   // Binding to use TestChrono
	auto f3 = std::bind(ThreadSum, v.begin(), v.end());	    // Moved to the bottom because it is not printing after the threads start
	  
	TestChrono(f2);  // This one is the fastest

	start = std::chrono::system_clock::now();
	sum = ParallelMult(v.begin(), v.end());   //Outside test chrono to make sure answer is 1 
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;

	std::cout << "Finished computation for mult accumulate at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << " answer is : " << sum << "s\n";


	/* 
	Below is the threading.   I cant seem to find the issue?
	*/

	start = std::chrono::system_clock::now();
	SUM = 0;
	ThreadSum(v.begin(), v.end());   //Outside test chrono to make sure answer is 1 
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;

	std::cout << "Finished computation for ThreadSum at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << " answer is : " << SUM << "s\n";

	TestChrono(f3);   // For some reason, once this is called can no long print?  
					  // Also i put a cout inside the lock, and expected to see the SUM increment by 625 to 10K
					  // however, it went up to 15K, most of the time by 625, but sometimes by random numbers

}