#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>


using Data =
std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;
using split_vector_type = std::vector<std::string>;


boost::gregorian::date DateConversion(std::string& s)
{// Takes string as yyyy-mm-dd and returns date

	split_vector_type v;
	split(v, s, boost::is_any_of("-"), boost::algorithm::token_compress_on);

	int year = boost::lexical_cast<int>(v[0]);
	int mm = boost::lexical_cast<int>(v[1]);
	int dd = boost::lexical_cast<int>(v[2]);

	return boost::gregorian::date(year, mm, dd);
}

std::vector<double> createVec(std::vector<std::string>& sv)
{
	// Takes vector of strings and converts to vector of doubles
	std::vector<double> output;

	for (auto i : sv)
	{
		output.push_back(boost::lexical_cast<double>(i));
	}
	return output;
}


template<typename Date, typename T>
ResultSet ReadFile(std::string filename)
{
	std::vector<std::string> _row;
	std::string line;
	ResultSet timeseries;
	Data row;

	try
	{
		std::ifstream infile(filename);

		
		if (!infile) std::cout << "Cant open file !";  // Identify if file open

		std::getline(infile, line);  // ingore first line

		while (getline(infile, line))  // While lines can be read
		{
			if (line.size() > 0)
			{
				boost::trim_if(line, boost::is_any_of(" ")); // remove all spaces
				split_vector_type v;

				boost::split(v, line, boost::is_any_of(","));  // split on commas

				auto date = DateConversion(v[0]);
				v.erase(v.begin()); // remove date from vector
				row = std::make_tuple(date, createVec(v));
				timeseries.push_back(row);
			}
		}
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return timeseries;
}

void PrintRow(Data& row)
{
	std::cout << std::get<0>(row) << ": ";

	for (auto i : std::get<1>(row))
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}


int main()
{
	std::string infile = "C:\\Users\\Shilo\\Desktop\\Advancedcpp\\Level 5\\Section 5.1\\Exercise 4\\infile.csv";   

	ResultSet timeseries = ReadFile<boost::gregorian::date, double>(infile);
	
	for (auto i : timeseries)
	{
		PrintRow(i);
	}
}

