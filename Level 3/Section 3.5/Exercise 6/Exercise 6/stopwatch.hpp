#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
#include <iostream>

class StopWatch
{
private:
	StopWatch(const StopWatch& s): start(s.start), end(s.end)
	{
	};

	StopWatch& operator = (const StopWatch& s)
	{
		if (this == &s) return *this;
		
		start = s.start; end = s.end; 
		return *this;
	}

	std::chrono::time_point
		<std::chrono::system_clock> start, end;
public:
	StopWatch()
	{};

	void StartStopWatch()
	{
		start = std::chrono::system_clock::now();  //Set Start Time
	}

	void StopStopWatch()
	{
		end = std::chrono::system_clock::now(); //Set End Time
	}

	void Reset()
	{
		start = std::chrono::time_point<std::chrono::system_clock>();
		end = std::chrono::time_point<std::chrono::system_clock>();
	}

	double GetTime() const
	{
		std::chrono::duration<double> elapsed_seconds = end - start;
		return elapsed_seconds.count();  // Return Difference
	}
};


#endif