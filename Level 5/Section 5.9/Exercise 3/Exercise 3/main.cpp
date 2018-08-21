#include <boost/signals2.hpp>
#include <iostream>



struct BootstrapCheck
{
	// Iterate in slots and return first 'false'
	// value; otherwise, 'true'
	typedef bool result_type;
template <typename InputIterator>
bool operator()(InputIterator first, InputIterator last) const
{
	while (first != last)
	{
		if (!*first)
			return false;
		++first;
	}
	return true;
}
};

int main()
{
	boost::signals2::signal<bool(), BootstrapCheck> sig;

	sig.connect([]() {return 1;});
	sig.connect([]() {return 0; });
	sig.connect([]() {return 1; });
	
	std::cout << sig();

}

