#include "SUD.hpp"
#include "Source.hpp"
#include "Sink.hpp"
#include "Process.hpp"

#include <string>
#include <vector>

// T1 = string
// T2 = string

std::string str_toupper(std::string s)
{ // helper function to convert string
std::transform(s.begin(), s.end(), s.begin(),
	[](unsigned char c) {return std::toupper(c); });
return s;
}



int main()
{
	std::string in = "infile.txt";
	std::string out = "outfile.txt";
	std::string out2 = "outfile2.txt";

	SUD<std::string, std::string, Source, Sink, Processing> mySUD(in, out);
	mySUD.run();

	SUD2<std::string, std::string, Source, Sink> mySUD2(in, out2);
	mySUD2.run(str_toupper);



}