#include "CharacterSystem.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\EnemyKilledObserverUI.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\SoldierKilledObserverUI.h>

#include <Engine\GameEngine\Includes.h>

#include <vector>

void Gameplay::CharacterSystem::_Init()
{
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::EnemyKilled, new Gameplay::EnemyKilledObserverUI());
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::SoldierKilled, new Gameplay::SoldierKilledObserverUI());
}

void Gameplay::CharacterSystem::_Update()
{
	_UpdateCharacter();
	_UpdateAI();
}

void Gameplay::CharacterSystem::_Release()
{
	for (auto soldier : m_Soldiers)
	{
		soldier->_Release();
	}

	m_Soldiers.clear();

	for (auto enemy : m_Enemies)
	{
		enemy->_Release();
	}

	m_Enemies.clear();
}

void Gameplay::CharacterSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	for (const auto i : m_Soldiers)
	{
		Engine::SubmitObjectToBeRendered(i_pScene, i->_GetGameObject());
	}

	for (const auto i : m_Enemies)
	{
		Engine::SubmitObjectToBeRendered(i_pScene, i->_GetGameObject());
	}
}


void Gameplay::CharacterSystem::_AddSoldier(Engine::Memory::shared_ptr<ICharacter> i_Soldier)
{
	m_Soldiers.push_back(i_Soldier);
}

void Gameplay::CharacterSystem::_AddEnemy(Engine::Memory::shared_ptr<ICharacter> i_Enemy)
{
	m_Enemies.push_back(i_Enemy);
}

void Gameplay::CharacterSystem::_RemoveCharacter()
{
	_RemoveCharacter(m_Soldiers, ENUM_GameEvent::SoldierKilled);
	_RemoveCharacter(m_Enemies, ENUM_GameEvent::EnemyKilled);
}

void Gameplay::CharacterSystem::_RemoveCharacter(std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Characters, ENUM_GameEvent emEvent)
{
	std::list<Engine::Memory::shared_ptr<ICharacter>> CanRemoves;

	for (auto character : i_Characters)
	{
		if (character->_IsKilled() == false)
			continue;

		if (character->_CheckKilledEvent() == false)
			m_pTDGame->_NotifyGameEvent(emEvent, character._Get());

		CanRemoves.push_back(character);
	}

	for (auto character : CanRemoves)
	{
		i_Characters.remove(character);
		character->_Release();
	}
}

void Gameplay::CharacterSystem::_UpdateCharacter()
{
	for (const auto soldier : m_Soldiers)
	{
		soldier->_Update();
	}

	for (const auto enemy : m_Enemies)
	{
		enemy->_Update();
	}
}

void Gameplay::CharacterSystem::_UpdateAI()
{
	_UpdateAI(m_Soldiers, m_Enemies);
	_UpdateAI(m_Enemies, m_Soldiers);
	_RemoveCharacter();
}

void Gameplay::CharacterSystem::_UpdateAI(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Characters, const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets)
{
	for (const auto character : i_Characters)
	{
		character->_UpdateAI(i_Targets);
	}
}
