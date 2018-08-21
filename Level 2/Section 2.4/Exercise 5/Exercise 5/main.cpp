#include <iostream>
#include <functional>
#include <memory>
#include <fstream>

auto FileClose(std::ofstream* fp)
{
	std::cout << "Closing File" << std::endl;
	fp->close();
}

int main()
{

	
	auto FileFinalizer = [](std::ofstream* fp)
	{
		std::cout << "Closing File" << std::endl;
		fp->close();
	};

	std::ofstream myFile("Test.txt");
	std::ofstream myFile2("Test2.txt");


	std::shared_ptr<std::ofstream> mySharedFile(&myFile, FileFinalizer);
	std::shared_ptr<std::ofstream> mySharedFile2(&myFile2, FileClose);

	try
	{
		for (int i = 0; i < 10; i++)
		{
			*mySharedFile << "Hello";
			*mySharedFile2 << "Hello";
			throw 1;

		}
	}
	catch (int e)
	{
		std::cout << mySharedFile->is_open() << std::endl;  // File is still open because the Deleter hasnt been called yet
	}



	return 0;
}