#ifndef SOURCE_HPP
#define SOURCE_HPP


#include <string>
#include <vector>
#include <fstream>
#include <iostream>



template<typename T1>
class Source
{
private:
	std::string fp;

public:
	Source(std::string _fp) : fp(_fp) {};  // Set file path

	std::vector<std::string> message() // to conform to interface
	{
		std::vector<std::string> output;
		std::string line;

		std::ifstream myfile(fp);

		if (!myfile)
		{ // In case file is lost
			std::cout << "File not Found" << std::endl;
			return std::vector<std::string>{"Error"};
		}

		while (std::getline(myfile, line))
		{// Read lines into vector
			output.push_back(line);
		}

		return output;   
	
	}

};

#endif