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
		if (soldier != nullptr)
		{
			soldier->_Release();
			delete soldier;
			soldier = nullptr;
		}
	}

	for (auto enemy : m_Enemies)
	{
		if (enemy != nullptr)
		{
			enemy->_Release();
			delete enemy;
			enemy = nullptr;
		}
	}
}

void Gameplay::CharacterSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	for (const auto i : m_Soldiers)
	{
		Engine::SubmitGameObject(i_pScene, i->_GetGameObject());
	}

	for (const auto i : m_Enemies)
	{
		Engine::SubmitGameObject(i_pScene, i->_GetGameObject());
	}
}


void Gameplay::CharacterSystem::_AddSoldier(ICharacter * i_Soldier)
{
	m_Soldiers.push_back(i_Soldier);
}

void Gameplay::CharacterSystem::_AddEnemy(ICharacter * i_Enemy)
{
	m_Enemies.push_back(i_Enemy);
}

void Gameplay::CharacterSystem::_RemoveCharacter()
{
	_RemoveCharacter(m_Soldiers, ENUM_GameEvent::SoldierKilled);
	_RemoveCharacter(m_Enemies, ENUM_GameEvent::EnemyKilled);
}

void Gameplay::CharacterSystem::_RemoveCharacter(std::list<ICharacter*>& i_Characters, ENUM_GameEvent emEvent)
{
	std::list<ICharacter*> CanRemoves;

	for (auto character : i_Characters)
	{
		if (character->_IsKilled() == false)
			continue;

		if (character->_CheckKilledEvent() == false)
			m_pTDGame->_NotifyGameEvent(emEvent, character);

		CanRemoves.push_back(character);
	}

	for (auto character : CanRemoves)
	{
		i_Characters.remove(character);
		character->_Release();
		delete character;
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

void Gameplay::CharacterSystem::_UpdateAI(const std::list<ICharacter*>& i_Characters, const std::list<ICharacter*>& i_Targets)
{
	for (const auto character : i_Characters)
	{
		character->_UpdateAI(i_Targets);
	}
}
