#ifndef SINKING_HPP
#define SINKING_HPP

#include <string>
#include <vector>
#include <fstream>


template<typename T2>
class Sink
{
private:
	std::string fp;
public:

	Sink(std::string _fp): fp(_fp) {}; // Set the file path

	void print(std::vector<T2> t)
	{
		std::ofstream file(fp);

		for (int i = 0; i < t.size(); i++)
			file << t[i] << std::endl;
	}

};
#endif