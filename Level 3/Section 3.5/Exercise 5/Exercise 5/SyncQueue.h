#ifndef SYNCQUEUE
#define SYNCQUEUE

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>


template<typename T>
class Queue
{
private:
	std::priority_queue<T> m_queue;
	std::mutex m_mutex;
	std::condition_variable cond_var_empty;
	std::condition_variable cond_var_full;
	int capacity;

public:
	
	Queue(int capacity) : capacity(capacity)
	{};

	void enqueue(T& item)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		while (capacity <= m_queue.size())
		{
			cond_var_full.wait(lock);
		}
		m_queue.push(item);
		cond_var_empty.notify_one();
		lock.unlock();
	}

	T dequeue()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		while (m_queue.empty())
		{
			cond_var_empty.wait(lock);
		}

		T item = m_queue.top();
		cond_var_full.notify_one();
		m_queue.pop();
		lock.unlock();
		return(item);
	}
};

#endif
