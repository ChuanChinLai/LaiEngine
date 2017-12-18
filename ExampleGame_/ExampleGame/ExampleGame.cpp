#include "ExampleGame.h"
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Scene\SceneManager.h>
#include <ExampleGame_\MainMenuScene\MainMenuScene.h>

bool Engine::GameDemo::_Init()
{
	if (!_InitSystem("TEST", 800, 600, false))
	{
		return false;
	}

	Engine::Resource::MainMenuScene* S1 = new Engine::Resource::MainMenuScene(_GetSceneManager());

	_GetSceneManager()->_SetGameScene(S1);

	return true;
}