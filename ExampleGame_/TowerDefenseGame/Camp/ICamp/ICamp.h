#pragma once

#include <Engine\Math\Vector4D.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>

namespace Gameplay
{
	class TowerDefenseGame;
	class CharacterAttr;

	class ICamp
	{
	public:

		inline ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName);
		virtual inline ~ICamp();

		inline void _SetTowerDefenseGame(TowerDefenseGame* i_pTDGame);
		inline void _SetAttributeData(const CharacterAttr& i_AttributeData);

		virtual inline void _RunCommand();

	protected:

		TowerDefenseGame*				m_pTDGame;
		Engine::Math::Vector4D<float>	m_Position;
		CharacterAttr					m_AttributeData;
		std::string						m_SpriteName;

	private:

	};
}

#include "ICamp_inline.h"