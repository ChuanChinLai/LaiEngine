#include <ExampleGame_\ExampleGame\EngineDemo.h>
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

	Engine::Memory::_ReleaseHeapManager();


#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	system("pause");

	return 0;
}