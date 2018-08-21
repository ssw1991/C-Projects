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
	std::queue<T> m_queue;
	std::mutex m_mutex;
	std::condition_variable cond_var_empty;
	std::condition_variable cond_var_full;
	int capacity;

public:
	
	Queue(int capacity) : capacity(capacity)
	{};

	void enqueue(T item)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		if (capacity <= m_queue.size())
		{
			item.leave();  // No longer using condition varaible because customer will leave
		}
		m_queue.push(item);
		lock.unlock();
		cond_var_empty.notify_one();  // Notify sleeping barber
	}

	T dequeue()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		while (m_queue.empty())
		{
			cond_var_empty.wait(lock);  // Barber wakes up if a customer enters the q
			// under this simulation (fixed interval not random) this only occurs in the beginning
			// as first customer doesnt show up for 10 minutes
		}

		T item = m_queue.front();  
		m_queue.pop();
		lock.unlock();
		return(item);    // Return customer to barber for cut
	}

	int size()
	{
		return m_queue.size();   // To test capacity better
	}
};

#endif
