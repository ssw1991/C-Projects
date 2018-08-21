#include <boost/signals2.hpp>
#include <iostream>
#include <numeric>


template<typename T>
struct Sum
{
	// Iterate over slots and accumulate
	typedef T result_type;
	template <typename InputIterator>
	T operator()(InputIterator first, InputIterator last) const
	{
		return std::accumulate(first, last, 0);
	}
};

int main()
{
	boost::signals2::signal<int(int, int), Sum<int>> sig;

	sig.connect([](int a, int b) {return a*b; });
	sig.connect([](int a, int b) {return a%b; });
	sig.connect([](int a, int b) {return a - b; });

	std::cout << sig(15, 20);

}

