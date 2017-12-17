#include "ExampleGame.h"
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Scene\SceneManager.h>
#include <Engine\Scene\IGameScene.h>

bool Engine::GameDemo::_Init()
{
	if (!_InitSystem("TEST", 800, 600, false))
	{
		return false;
	}

//	Engine::Resource::IGameScene* S1 = new Engine::Resource::IGameScene(_GetSceneManager());

//	_GetSceneManager()->_SetGameScene(S1);

	return true;
}