#ifndef SUD_HPP
#define SUD_HPP

#include <functional>
#include <string>
#include <algorithm>


template <typename T1, typename T2,
	template <typename T1> class Source,
	template <typename T2> class Sink,
	template <typename T1, typename T2> class Processing>
class SUD : private Source<T1>, private Sink<T2>, private Processing<T1, T2>
{
private:

	using Source<T1>::message;
	using Processing<T1,T2>::convert;
	using Sink<T2>::print;

public:

	SUD(std::string in, std::string out) : Source<T1>(in), Sink<T2>(out) {};  // Call parent constructors
	void run()
	{
		auto s = message();
		s = convert(s);
		print(s);
	}
};


template <typename T1, typename T2,
	template <typename T1> class Source,
	template <typename T2> class Sink>
class SUD2 : private Source<T1>, private Sink<T2>
{
private:

	using Source<T1>::message;
	using Sink<T2>::print;

public:
	SUD2(std::string in, std::string out) : Source<T1>(in), Sink<T2>(out) {};  // Call parent constructors
	void run(std::function<T2(T1)> f)
	{
		auto s = message();
		std::transform(s.begin(), s.end(), s.begin(), f);
		print(s);
	}

};

#endif