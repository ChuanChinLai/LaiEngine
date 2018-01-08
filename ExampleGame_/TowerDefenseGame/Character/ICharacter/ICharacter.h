#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Engine
{
	namespace Asset
	{
		class SpriteObject;
		class TextObject;
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

		bool _IsKilled();
		bool _CheckKilledEvent();

		float  _GetATK();

		Engine::Asset::SpriteObject* _GetGameObject();
		Engine::Asset::TextObject*	 _GetTextObject_HP();

		CharacterAttr*				 _GetAttribute();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;
		Engine::Asset::TextObject*   m_pTextObject_HP;

		CharacterAttr*				 m_pAttribute;
		ICharacterAI*				 m_pAI;
	private:
		bool m_bKilled;
		bool m_bCheckKilled;
	};
}