#include "EnemyCamp.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>

#include <Engine\GameEngine\Includes.h>

Gameplay::EnemyCamp::EnemyCamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName): ICamp(i_Position, i_SpriteName), m_Time(m_SpawnTime)
{

}

Gameplay::EnemyCamp::~EnemyCamp()
{

}

void Gameplay::EnemyCamp::_RunCommand()
{
	m_Time -= Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	if (m_Time > 0)
		return;

	m_Time = m_SpawnTime;

	ICharacter* pNewCharacter = new Enemy();
	pNewCharacter->_Init();
	pNewCharacter->_SetAttribute(new CharacterAttr(m_pAttributeData));


	Engine::Asset::Sprite* pSprite = pNewCharacter->_GetGameObject()->_GetComponent<Engine::Asset::Sprite>();
	pSprite->_Create(m_SpriteName);
	pNewCharacter->_GetGameObject()->m_Position = m_Position;

	m_pTDGame->_AddEnemy(pNewCharacter);
}
