#include "CharacterSystem.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <vector>

void Gameplay::CharacterSystem::_Update()
{
	_UpdateCharacter();
}

void Gameplay::CharacterSystem::AddSoldier(ICharacter * i_Soldier)
{
	m_Soldiers.push_back(i_Soldier);
}

void Gameplay::CharacterSystem::AddEnemy(ICharacter * i_Enemy)
{
	m_Enemies.push_back(i_Enemy);
}

void Gameplay::CharacterSystem::_UpdateCharacter()
{

}
