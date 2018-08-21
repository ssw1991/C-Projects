#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include "SyncQueue.h"
#include <iostream>
#include <chrono>
#include <thread>



bool CONSUMER_OPEN = true;

struct Customer
{
	void leave()
	{//A way to test if the client left
		std::cout << "Customer Left" << std::endl;
	}

	void haircut()
	{ // Testing if client was seated for haircut
		std::cout << "Customer happy" << std::endl;
	}
};


class CustomerProducer
{
	// Simple Producer Class which will enter an integer into the queue
private:
	Queue<Customer>* m_queue;

public:
	CustomerProducer(Queue<Customer>* q) : m_queue(q)
	{};
	void operator ()()
	{
		while (CONSUMER_OPEN)  // Flag variable to see if barber is open
		{
			std::this_thread::sleep_for(std::chrono::duration<int>(1)); // sleep for 1 second (for convienience, represents 10 sec)
			m_queue->enqueue(Customer());  // Add customer to queue,  that function sends the customer home if not available
		}
	}
};

class Barber
{
private:
	Queue<Customer>* m_queue;
	std::chrono::time_point<std::chrono::system_clock> close;  // a closing time 
public:
	Barber(Queue<Customer>* q) : m_queue(q)
	{
		close = std::chrono::system_clock::now() + std::chrono::duration<int>(48); // represents 8 hours
	}
	void operator()()
	{
		
		while ((std::chrono::system_clock::now() <= close))    // While open
		{
			std::this_thread::sleep_for(std::chrono::duration<int>(2));    // 20 minutes per haircut
			Customer C = m_queue->dequeue();
			C.haircut();  //Client recieves haircut
		}
		CONSUMER_OPEN = false;  // Close shop

	}
};


#endif
