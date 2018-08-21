#include <iostream>
#include "stopwatch.hpp"
#include <chrono>
#include <thread>



int main()
{
	StopWatch S;

	S.StartStopWatch();
	std::this_thread::sleep_for(std::chrono::duration<int>(2));
	S.StopStopWatch();

	std::cout << S.GetTime() << std::endl;

	// StopWatch S1 = S; Private
	// StopWatch S2(S) Private

	S.Reset();
	std::cout << S.GetTime() << std::endl;

	return 0;
}