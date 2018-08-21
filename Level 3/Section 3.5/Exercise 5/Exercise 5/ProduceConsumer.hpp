#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include "SyncQueue.h"
#include <iostream>

std::mutex coutmtx;
template<typename T>
class Producer
{
	// Simple Producer Class which will enter an integer into the queue
private:
	Queue<T>* m_queue;

public:
	Producer(Queue<T>* q) : m_queue(q)
	{};
	void operator ()(int n)
	{
		for (int i = 0; i <= n; i++)
			m_queue->enqueue(i);
	}
};

template<typename T>
class Consumer
{
private:
	Queue<T>* m_queue;
public:
	Consumer(Queue<T>* q) : m_queue(q)
	{};

	void operator()()
	{
		while (COMMAND)
		{
			while (! coutmtx.try_lock()) {};  //Repeatedly try lock until it is gained
			std::cout << m_queue->dequeue() << std::endl;
			coutmtx.unlock();
		}

	}
};

#endif
