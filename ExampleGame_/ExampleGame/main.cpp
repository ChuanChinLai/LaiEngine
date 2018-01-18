#include <stdlib.h>

#include <ExampleGame_\ExampleGame\EngineDemo.h>
#include <Engine\Math\Vector4D.h>
#include <Engine\GameObject\GameObject.h>
#include <Engine\GameObject\Components\Transform.h>

#include "Test.h"
#include <Engine\Tool\Tool.h>
#include <ExampleGame_\TowerDefenseGame\Camp\CampSystem\CampSystem.h>
#include <list>

#include <Engine\Memory\HeapManager\HeapManager.h>




int main(int argc, char *args[])
{
	Engine::Memory::_InitHeapManager();
	Engine::Memory::HeapManager_UnitTest();


	Engine::EngineDemo Game;

	if (!Game._Init())
	{
		Game._Release();
		return 0;
	}

	Game._Loop();

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	system("pause");

	return 0;
}