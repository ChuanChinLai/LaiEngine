#include "EngineDemo.h"
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Scene\SceneManager.h>
#include <ExampleGame_\TowerDefenseGame\Scene\GamingScene\GamingScene.h>
#include <ExampleGame_\TowerDefenseGame\Scene\MainMenuScene\MainMenuScene.h>

bool Engine::EngineDemo::_Init()
{
	if (!_InitSystem("Tower Defense Game", 800, 600, false))
	{
		return false;
	}

	Engine::MainMenuScene* S1 = new Engine::MainMenuScene(_GetSceneManager()._Get());

	_GetSceneManager()->_SetGameScene(S1);

	return true;
}