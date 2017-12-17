#include <stdlib.h>
#include <iostream>

#include <External\SDL2\Includes.h>
#include <stdio.h>

#include <fstream>
#include <filesystem>

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Input\Input.h>
#include <ExampleGame\ExampleGame.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\SmartPointer\WeakPointer.h>

int main(int argc, char *args[])
{

	Engine::GameDemo* Game = new Engine::GameDemo();

	if (!Game->_Init())
	{
		Game->_Release();
		return 0;
	}

	Game->_Loop();

	delete Game;

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	system("pause");

	return 0;
}