#include <vector>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <ctime>
#include "TmpProcessor.hpp"

std::vector<double> F1(std::vector<double> v)
{ // Simple Functions to test
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	return (out);
}

std::vector<double> F2(std::vector<double> v)
{
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	return (out);
}

std::vector<double> F3(std::vector<double> v)
{
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	return (out);
}

std::vector<double> F4(std::vector<double> v, std::vector<double> v1)
{
	std::vector<double> out;
	for (int i = 0; i < v.size(); i++)
	{
		out.push_back(v[i] + v1[i]);
	}

	return (out);
}

std::vector<double> SerialTaskGraph(std::vector<double> v)
{
	// Straight forward Serial implementation

	std::vector<double> b = F1(v);
	std::vector<double> c = F2(v);
	std::vector<double> d = F3(v);
	return F4(b, d);
}

std::vector<double> ParalellTaskGraphFuture(std::vector<double> v)
{
	// Create a future for b, c, and d
	std::future<std::vector<double>> b(std::async(F1, v));
	std::future<std::vector<double>> c(std::async(F2, v));
	std::future<std::vector<double>> d(std::async(F3, c.get()));  //Get c's output for F3
	return F4(b.get(), d.get()); // Call function on final output
}

std::vector<double> Fact()
{
	std::vector<double> v;
	for (int i = 0; i < 1000000; i++)
	{ // Long algo
		v.push_back(i);
	}
	return v;
}

void Dis(std::vector<double>& v)
{
	std::cout << "Completed!!!";
}

int main()
{

	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	

	start = std::chrono::system_clock::now();
	
	TmpProcessor<std::vector<double>> t1(Fact, SerialTaskGraph, Dis);
	t1.algorithm();

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished serial computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";
	

	start = std::chrono::system_clock::now();

	TmpProcessor<std::vector<double>> t2(Fact, ParalellTaskGraphFuture, Dis);
	t2.algorithm();

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished paralell computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

}