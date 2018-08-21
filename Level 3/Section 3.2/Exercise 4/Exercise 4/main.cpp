#include <string>
#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <sstream>


// Types and data needed
int data;// Shared data between master and worker
std::mutex m; // Ensures no race condition
int count(0); // to count passing multiple tasks
std::condition_variable cv;   // Synchronization between master and worker

// Initial state of worker and master
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;

void worker_thread()
{
	std::stringstream ss;
	std::unique_lock<std::mutex> lk(m);             // obtain lock 
	cv.wait(lk, [] {return masterReady.load();});   // wait to be notified and master to be ready
	workerReady = false;                            // Worker now busu
	data = data * data;							    // worker squares data (does task)
	workerReady = true;                             // worker ready
	lk.unlock();                                    // Unlock
	cv.notify_one();                                // Notify
}



int main()
{
	std::thread worker(worker_thread);

	data = 15;                            // Set data
	// send data to the worker thread
	
		std::unique_lock<std::mutex> lk(m); // Establish lock
		masterReady = true;                // set Ready
		lk.unlock();
	    cv.notify_one();                        // Notify worker

	
		lk.lock();  // Set lock 
		cv.wait(lk, [] {return workerReady.load(); }); // wait for worker
		std::cout << "At the Master, data = " << data << '\n';

	worker.join();
}