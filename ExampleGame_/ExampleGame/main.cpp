#include <stdlib.h>

#include <ExampleGame_\ExampleGame\EngineDemo.h>
#include <Engine\Math\Vector4D.h>

int main(int argc, char *args[])
{

	Engine::EngineDemo* Game = new Engine::EngineDemo();

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