#include "CharacterSystem.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <vector>

void Gameplay::CharacterSystem::_Update()
{
	_UpdateCharacter();
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
}

void Gameplay::CharacterSystem::AddSoldier(ICharacter * i_Soldier)
{
	m_Soldiers.push_back(i_Soldier);
}

void Gameplay::CharacterSystem::AddEnemy(ICharacter * i_Enemy)
{
	m_Enemies.push_back(i_Enemy);
}

const std::list<Gameplay::ICharacter*>& Gameplay::CharacterSystem::_GetSoldiers()
{
	return m_Soldiers;
}

void Gameplay::CharacterSystem::_UpdateCharacter()
{
	for (const auto soldier : m_Soldiers)
	{
		soldier->_Update();
	}
}
