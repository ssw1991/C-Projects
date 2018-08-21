#include<queue>
#include "ProduceConsumer.hpp"
#include "SyncQueue.h"
#include <thread>

int main()
{

	Queue<Customer> q(12);
	CustomerProducer p(&q);
	Barber b(&q);

	
	std::thread producer(p);
	std::thread consumer(b);
	consumer.join();
	producer.join();
	
}


