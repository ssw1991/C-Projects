#ifndef SUBJECT_HPP
#define SUBJECT_hpp

#include <boost/function.hpp>
#include <list>
#include <iostream>



// Using boost Function library
typedef boost::function<void(double)> FunctionType;

class Subject
{
	// The notifier (Observable)in Publisher-Subscriber pattern
private:
	std::list<FunctionType> attentionList;
public:
	Subject() { attentionList = std::list<FunctionType>(); }
	void AddObserver(const FunctionType& ft)
	{
		attentionList.push_back(ft);
	}

	void ChangeEvent(double x)
	{
		for (auto it = attentionList.begin();
			it != attentionList.end(); ++it) {
			(*it)(x);
		}
	}
};

#endif