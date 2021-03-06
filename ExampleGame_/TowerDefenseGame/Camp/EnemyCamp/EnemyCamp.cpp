#include "EnemyCamp.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\EnemyAI.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>

#include <Engine\GameEngine\Includes.h>
#include <ctime>


Gameplay::EnemyCamp::EnemyCamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName): ICamp(i_Position, i_SpriteName), m_Time(2.0f)
{
	srand(static_cast <unsigned> (time(0)));
}

Gameplay::EnemyCamp::~EnemyCamp()
{

}

void Gameplay::EnemyCamp::_RunCommand()
{
	m_Time -= Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	if (m_Time > 0)
		return;

	m_Time = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / m_MaxSpawnTime));
	
	Engine::Memory::shared_ptr<ICharacter> pNewCharacter(new Enemy);

	pNewCharacter->_Init();
	pNewCharacter->_SetCharacterAI(Engine::Memory::shared_ptr<ICharacterAI>(new EnemyAI(pNewCharacter)));
	pNewCharacter->_SetAttribute(Engine::Memory::shared_ptr<CharacterAttr>(new CharacterAttr(m_AttributeData)));
	pNewCharacter->_SetPosition(m_Position);

	Engine::Component::Sprite* pSprite = pNewCharacter->_GetGameObject()->_GetComponent<Engine::Component::Sprite>();
	pSprite->_Create(m_SpriteName);

	m_pTDGame->_AddEnemy(pNewCharacter);
}
