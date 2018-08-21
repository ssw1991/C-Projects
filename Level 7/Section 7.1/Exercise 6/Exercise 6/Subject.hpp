// Subject


#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <list>
#include <memory>

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template< template<class, class> class Container, typename Func, typename Alloc = std::allocator<Func>>
class Subject
{
private:
	Container<Func, Alloc> data;

public:

	void Attach(Func o)
	{
		data.push_back(o);
	};

	void Remove()
	{ // To conform to the stl containers interface
		data.pop_back();
	};

	void Notify()
	{
		
		for(auto i: data)
		{
			i(this->GetCounter());
		}
	};
	
	virtual int GetCounter() =0;  // Had to include in base so that it can be called from a subject pointer
};
#endif