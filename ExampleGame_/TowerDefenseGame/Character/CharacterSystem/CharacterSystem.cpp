#include "CharacterSystem.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <vector>

void Gameplay::CharacterSystem::_Update()
{
	_UpdateCharacter();
}

const std::vector<Gameplay::ICharacter*>& Gameplay::CharacterSystem::_GetSoldiers()
{
	return m_Soldiers;
}

void Gameplay::CharacterSystem::_UpdateCharacter()
{

}
