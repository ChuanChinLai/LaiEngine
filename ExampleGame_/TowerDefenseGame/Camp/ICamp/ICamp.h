#pragma once

#include <Engine\Math\Vector4D.h>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
	}
}

namespace Gameplay
{
	class TowerDefenseGame;
	class CharacterAttr;

	class ICamp
	{
	public:

		inline ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName);
		virtual inline ~ICamp();

		void _SetTowerDefenseGame(TowerDefenseGame* i_pTDGame);
		void _SetAttributeData(CharacterAttr* i_pAttributeData);

		virtual inline void _RunCommand();

	protected:

		TowerDefenseGame*				m_pTDGame;
		CharacterAttr*					m_pAttributeData;

		Engine::Math::Vector4D<float>	m_Position;
		std::string						m_SpriteName;

	private:

	};
}

#include "ICamp_inline.h"