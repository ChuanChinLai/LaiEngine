#include "EngineDemo.h"
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Scene\SceneManager.h>
#include <ExampleGame_\TowerDefenseGame\Scene\GamingScene\GamingScene.h>
#include <ExampleGame_\TowerDefenseGame\Scene\MainMenuScene\MainMenuScene.h>
#include <ExampleGame_\TowerDefenseGame\Scene\TutorialScene\TutorialScene.h>

bool Engine::EngineDemo::_Init()
{
	if (!_InitSystem("Tower Defense Game", 800, 600, false))
	{
		return false;
	}

	Engine::MainMenuScene* pScene = new Engine::MainMenuScene(_GetSceneManager());

	_GetSceneManager()->_SetGameScene(pScene);

	return true;
}