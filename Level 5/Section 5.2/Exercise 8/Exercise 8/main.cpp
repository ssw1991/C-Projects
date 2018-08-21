#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>
#include <regex>



std::regex myTimeseries("(\\d{4}-\\d{2}-\\d{2}),(\\d{1,}\\.\\d{2}),(\\d{1,}\\.\\d{2}),(\\d{1,}\\.\\d{2}),(\\d{1,}\\.\\d{2}),(\\d+),(\\d{1,}\\.\\d{2})");
/*
Matches the timeseries data from previous example
(\\d{4}-\\d{2}-\\d{2})  - group to match date ####-##-##
, - match comma
(\\d{1,}\\.\\d{2},){4} - matches something to be cast to double, repeated 4 times seperated by comma
(one or more digits).(two digits) '.' escaped because it also means any character
(\\d{1,})   - group to match volume

Final group matches double again
*/


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
				std::smatch s;
				std::regex_search(line, s, myTimeseries);

				std::string date_string(s[1]);   
				// s contains pointers that match whole string, date, open, high, low, close, volume, adj close
				
				auto date = DateConversion(date_string);
				std::vector<double> v;  // empty vector to be filled
				
				for (int i = 2; i < s.size(); i++)
				{
					std::string double_string (s[i]);  // implicity convert to string
					v.push_back(boost::lexical_cast<double>(double_string)); // fill vector
				}
				
				row = std::make_tuple(date, v);  // make the row
				timeseries.push_back(row);  // add the row
				
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
	std::string infile = "C:\\Users\\Shilo\\Desktop\\Advancedcpp\\Level 5\\Section 5.2\\Exercise 8\\infile.csv";

	ResultSet timeseries = ReadFile<boost::gregorian::date, double>(infile);

	for (auto i : timeseries)
	{
		PrintRow(i);
	}
}

