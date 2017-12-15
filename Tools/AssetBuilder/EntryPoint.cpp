#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

int main(int i_argumentCount, char** i_arguments)
{
	std::string s1 = "C:\\Users/u1070737/Desktop/TowerDefenseGame/temp/x86/Debug/output/123.txt";
	std::string s2 = "C:\\Users/u1070737/Desktop/TowerDefenseGame/temp/x86/Debug/output/234.txt";

	if(!std::experimental::filesystem::exists(s2))
		std::experimental::filesystem::copy(s1, s2);
}
