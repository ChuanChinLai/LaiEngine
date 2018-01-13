#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>

#include <External\SDL2\Includes.h>
#include <External\Lua\Includes.h>

#include <unordered_map>
#include <string>

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class TowerDefenseGame;

	class ICamp;
	class SoldierCamp;
	class EnemyCamp;

	class CampSystem : public IGameSystem
	{

	public:

		CampSystem(TowerDefenseGame* i_pTDGame);

		virtual void _Init()	override;
		virtual void _Update()	override;
		virtual void _Release() override;

		void _RenderObjects(Engine::IGameScene* i_pScene) const;

	private:

		SDL_Scancode SoldierCampFactory(Soldier::TYPE emSoldier);

		bool _LoadCampDataFromLua(std::string i_FilePath);
		bool _LoadCampTableValues(lua_State& io_luaState);

		bool _LoadSoldierCampTableValues(lua_State& io_luaState);
		bool _LoadEnemyCampTableValues(lua_State& io_luaState);

		std::unordered_map<Soldier::TYPE, ICamp*>	m_SoldierCamps;
		std::unordered_map<Enemy::TYPE, ICamp*>		m_EnemyCamps;
	};
}