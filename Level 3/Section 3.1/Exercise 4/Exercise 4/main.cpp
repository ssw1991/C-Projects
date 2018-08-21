#include<queue>
#include "ProduceConsumer.hpp"
#include "SyncQueue.h"
#include <thread>

int main()
{

	Queue<int> q(5);
	Producer<int> p(&q);
	Consumer<int> c(&q);

	
	std::thread producer(p,1000);
	std::thread consumer(c, 1000);
	consumer.join();
	producer.join();
	
}


