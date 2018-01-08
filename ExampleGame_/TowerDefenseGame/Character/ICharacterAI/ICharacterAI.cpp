#include "ICharacterAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Math\Vector4D.h>

Gameplay::ICharacterAI::ICharacterAI(ICharacter* i_Character)
{
	m_Character = i_Character;
}

Gameplay::ICharacterAI::~ICharacterAI()
{
}

void Gameplay::ICharacterAI::ChangeAIState(IAIState * NewAIState)
{
}

void Gameplay::ICharacterAI::_MoveTo(const Engine::Math::Vector4D<float>& i_Position)
{
	if (Engine::Math::distance(m_Character->_GetGameObject()->m_Position, i_Position) < 48.0f)
	{
		return;
	}

	Engine::Math::Vector4D<float> dir = i_Position - m_Character->_GetGameObject()->m_Position;
	dir.normalize();

	float v = m_Character->_GetAttribute()->_GetSpeed();
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_Character->_GetGameObject()->m_Position += dir * v * t;
}

void Gameplay::ICharacterAI::_Update(const std::list<ICharacter*>& i_Targets)
{
	float min_distance = 1000.0f;
	ICharacter* nearest_character = nullptr;

	for (const auto target : i_Targets)
	{
		float d = Engine::Math::distance(m_Character->_GetGameObject()->m_Position, target->_GetGameObject()->m_Position);

		if (d < min_distance)
		{
			nearest_character = target;
			min_distance = d;
		}
	}

	if (nearest_character)
	{
		_MoveTo(nearest_character->_GetGameObject()->m_Position);

		if (Engine::Math::distance(m_Character->_GetGameObject()->m_Position, nearest_character->_GetGameObject()->m_Position) < 48.0f)
		{
			m_Character->_GetAttribute()->_CallDamageValue(nearest_character);
		}
	}
}
