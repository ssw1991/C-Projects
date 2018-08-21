#include <random>
#include <thread>
#include <iostream>
#include <chrono>
#include <future>
#include <cmath>
#include <queue>

// Thread function
double compute(double x, double y)
{
	// Wait a while
	std::default_random_engine dre(42);
	std::uniform_int_distribution<int> delay(0, 1000);
	std::this_thread::sleep_for
	(std::chrono::milliseconds(delay(dre)));
	return std::cos(x) * std::exp(y);
}


int main()
{


	double x = 0.0; double y = 2.71;
	
	std::packaged_task<double(double, double)> myTask(compute);  // Create task, assign function
	auto f = myTask.get_future(); // assign future
	myTask(x, y); //execute task

	// Get the shared data
	double result = f.get();   //get result
	std::cout << "Result: " << result << '\n';
	
	std::queue<std::packaged_task<double(double, double)>> q;  //declare queue
	for (int i = 0; i < 5; i++) // fill queue
		 q.push(std::packaged_task<double(double, double)>(compute));

	while (q.size() > 0)
	{
		std::packaged_task<double(double,double)> task = std::move(q.front());  //move taks to temporary object
		q.pop(); // pop task from queue
		auto f = task.get_future(); // assign future
		task(x,y); // execute
		std::cout << "Result: " << f.get() << '\n'; //get result
	}
}