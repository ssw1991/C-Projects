#include <iostream>
#include <fstream>
#include <system_error>
#include <string>

int main()
{
	std::ifstream file(std::string("DOESNOTEXIST.txt"));
	try
	{
		// Set the exception mask of the file stream
		// In this case 1) logical error on I/O operation or
		// 2) read/write error on I/O operation
		file.exceptions(file.failbit | file.badbit);
	}
	catch (const std::ios_base::failure& e)
	{
		if (e.code() == std::io_errc::stream)
		{
			std::error_code ec1(e.code());
			std::error_condition ec2(ec1.value(), ec1.category());
			std::cout << "Value: " << ec2.value() << " Category: " << ec2.category().name() << " Message: " << ec2.message() <<std::endl;

		}
	}
	catch (...)
	{
		std::cout << "catch all\n";
	}


	return 0;
}