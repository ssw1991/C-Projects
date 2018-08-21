#include <boost/system/error_code.hpp>
#include <string>
#include <iostream>
#include <fstream>

boost::system::error_condition ReadFile(std::string file)
{
	std::ifstream in(file.c_str());

	if (!in.is_open())
		return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
	
	std::cout << in.rdbuf() << std::endl;
	in.close();
	return boost::system::error_condition();
}

std::error_condition ReadFile2(std::string file)
{
	std::ifstream in(file.c_str());

	if (!in.is_open())
		return std::errc::no_such_file_or_directory;

	std::cout << in.rdbuf() << std::endl;
	in.close();
	return std::errc::no_message;
}
int main()
{
	std::string fp1 = "text.txt";
	std::string fp2 = "NOFILE.txt";

	boost::system::error_condition c1 = ReadFile(fp1);
	boost::system::error_condition c2 = ReadFile(fp2);

	std::cout << c1.message() << std::endl;
	std::cout << c2.message() << std::endl;

	std::error_condition c3 = ReadFile2(fp1);
	std::error_condition c4 = ReadFile2(fp2);

	std::cout << c3.message() << std::endl;
	std::cout << c4.message() << std::endl;
}
