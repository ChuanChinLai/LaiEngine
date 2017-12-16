#include <stdlib.h>
#include <iostream>

#include <External\SDL2\Includes.h>
#include <stdio.h>

#include <fstream>
#include <filesystem>

#include <Engine\GameEngine\GameEngine.h>

int main(int argc, char *args[])
{
	Engine::GameEngine GE;

	GE._Init();

	GE._Loop();

	return 0;
}