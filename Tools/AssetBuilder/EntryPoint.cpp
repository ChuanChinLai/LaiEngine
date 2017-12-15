#include <iostream>
#include <fstream>
#include <filesystem>

int main(int i_argumentCount, char** i_arguments)
{
	std::experimental::filesystem::copy_file("123.txt", "234.txt");
}
