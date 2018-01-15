#pragma once

#include <Engine\Math\Vector4D.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <list>

namespace Engine
{
	class GameObject;
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

		Engine::GameObject*				_GetGameObject();
		Engine::Math::Vector4D<float>	_GetPosition();
		CharacterAttr*					_GetAttribute();

		float							_GetATK();

		void _SetAttribute(CharacterAttr* i_pAttribute);

	protected:

		Engine::Memory::shared_ptr<Engine::GameObject>	m_pGameObject;
		CharacterAttr*				m_pAttribute;
		ICharacterAI*				m_pAI;

	private:
		bool m_bKilled;
		bool m_bCheckKilled;
	};
}