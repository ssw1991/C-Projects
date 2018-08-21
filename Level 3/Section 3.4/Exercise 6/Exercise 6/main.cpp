#include <vector>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <ctime>

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

void F1Promise(std::promise<std::vector<double>>& p, std::vector<double> v)
{// for F1 - F3 Promise
	// must take promise by ref and set_value
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	p.set_value(out);
}

void F2Promise(std::promise<std::vector<double>>& p, std::vector<double> v)
{
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	p.set_value(out);
}

void F3Promise(std::promise<std::vector<double>>& p, std::vector<double> v)
{
	std::vector<double> out;
	for (double i : v)
	{
		out.push_back(i*2.0);
	}

	p.set_value(out);
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

std::vector<double> ParalellTaskGraphPromise(std::vector<double> v)
{
	// Create a promise  and assign future for b, c, and d

	std::promise<std::vector<double>> b;
	std::thread t(F1Promise, std::ref(b), v);  //F1Promise must update promise
	std::future<std::vector<double>> futb(b.get_future());
	
	std::promise<std::vector<double>> c;
	std::thread t2(F2Promise, std::ref(c), v);  //F1Promise must update promise
	std::future<std::vector<double>> futc(c.get_future());

	// Join because it is needed for next function
	t2.join();

	std::promise<std::vector<double>> d;
	std::thread t3(F3Promise, std::ref(d),futc.get());  //F1Promise must update promise
	std::future<std::vector<double>> futd(d.get_future());

	t.join();
	t3.join();  //Join because they are needed in next function

	return F4(futb.get(), futd.get());  // Call final Function
}

std::vector<double> ParalellTaskGraphPackaged(std::vector<double> v)
{// Create a packaged_task for F1
	std::packaged_task<std::vector<double>(std::vector<double>)> ptask(F1);
	//Assign Future
	auto b = ptask.get_future();
	//Start Task
	ptask(v);
	//Run rest serially as F1 runs in back
	std::vector<double> c = F2(v);
	std::vector<double> d = F3(c);
	return F4(b.get(), d);
}



int main()
{
	// Setting Variables for Timing
	std::chrono::time_point
		<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
	// Large Input Vec
	std::vector<double> input;

	for (int i = 0; i < 10000; i++)
	{
		input.push_back(i);
	}
	
	
	start = std::chrono::system_clock::now();

	auto output = SerialTaskGraph(input); // Calling function wrapped in timing code

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished serial computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

	start = std::chrono::system_clock::now();

	output = ParalellTaskGraphFuture(input);

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished Paralell using Future computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

	start = std::chrono::system_clock::now();

	output = ParalellTaskGraphPackaged(input);

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished Paralell using Packaged Tasks computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

	start = std::chrono::system_clock::now();

	output = ParalellTaskGraphPromise(input);

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Finished paralell using Promises computation at "
		<< "elapsed time: "
		<< elapsed_seconds.count() << "s\n";

	return(0);
}