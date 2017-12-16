#include <stdlib.h>
#include <iostream>

#include <External\SDL2\Includes.h>
#include <stdio.h>

#include <fstream>
#include <filesystem>

#include <Engine\Graphics\Graphics.h>


int main(int argc, char *args[])
{

	Engine::Graphics g;

	g._Init("TEST", 800, 600);
	g._Update();

	system("pause");

	return 0;
}