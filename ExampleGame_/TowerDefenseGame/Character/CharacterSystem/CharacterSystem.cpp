#include "CharacterSystem.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <vector>

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

void Gameplay::CharacterSystem::AddSoldier(ICharacter * i_Soldier)
{
	m_Soldiers.push_back(i_Soldier);
}

void Gameplay::CharacterSystem::AddEnemy(ICharacter * i_Enemy)
{
	m_Enemies.push_back(i_Enemy);
}

void Gameplay::CharacterSystem::RemoveCharacter()
{
	RemoveCharacter(m_Soldiers, m_Enemies);
}

void Gameplay::CharacterSystem::RemoveCharacter(std::list<ICharacter*>& i_Characters, std::list<ICharacter*>& i_Opponents)
{
	std::list<ICharacter*> CanRemoves;

	for (auto character : i_Characters)
	{
		if (character->_IsKilled() == false)
			continue;

		CanRemoves.push_back(character);
	}

	for (auto character : CanRemoves)
	{
		i_Characters.remove(character);
		character->_Release();
		delete character;
	}
}

const std::list<Gameplay::ICharacter*>& Gameplay::CharacterSystem::_GetSoldiers()
{
	return m_Soldiers;
}

const std::list<Gameplay::ICharacter*>& Gameplay::CharacterSystem::_GetEnemies()
{
	return m_Enemies;
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

	RemoveCharacter();
}

void Gameplay::CharacterSystem::_UpdateAI(const std::list<ICharacter*>& i_Characters, const std::list<ICharacter*>& i_Targets)
{
	for (const auto character : i_Characters)
	{
		character->_UpdateAI(i_Targets);
	}
}
