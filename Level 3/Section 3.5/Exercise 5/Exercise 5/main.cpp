#include<queue>
#include "ProduceConsumer.hpp"
#include "SyncQueue.h"
#include <thread>

bool COMMAND = true;
int main()
{

	Queue<int> q(15);
	Producer<int> p(&q);
	Consumer<int> c(&q);

	
	std::vector<std::thread> producers;
	std::vector<std::thread> consumers;

	for (int i = 0; i < 10; i++)
	{
		producers.emplace_back(Producer<int>(&q), 100);
	}
	
	for (int i = 0; i < 5; i++)
	{
		consumers.emplace_back(Consumer<int>(&q));
	}
	
	for (auto& th : producers) th.join();
	COMMAND = false;
	for (auto& th : consumers) th.join();
}


