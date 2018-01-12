#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
	}
}

namespace Gameplay
{
	class CharacterAttr;
	class ICharacterAI;

	class ICharacter
	{
	public:
		ICharacter();
		virtual ~ICharacter();

		virtual void _Init();
		virtual void _Update();
		virtual void _Release();

		void _UpdateAI(const std::list<ICharacter*>& i_Targets);
		void _Killed();
		bool _IsKilled();
		bool _CheckKilledEvent();

		float  _GetATK();

		Engine::Asset::GameObject*	_GetGameObject();
		CharacterAttr*				_GetAttribute();

		void _SetAttribute(CharacterAttr* i_pAttribute);

	protected:
		Engine::Asset::GameObject*	m_pGameObject;
		CharacterAttr*				m_pAttribute;
		ICharacterAI*				m_pAI;
	private:
		bool m_bKilled;
		bool m_bCheckKilled;
	};
}