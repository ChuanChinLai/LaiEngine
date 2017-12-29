#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Engine
{
	namespace Asset
	{
		class SpriteObject;
	}
}

namespace Gameplay
{
	class ICharacter
	{
	public:
		ICharacter();
		~ICharacter();

		virtual void _Init();
		virtual void _Update();
		virtual void _Release();

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);
		void _UpdateAI(const std::list<ICharacter*>& i_Target);

		Engine::Asset::SpriteObject* _GetGameObject();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;

	private:
	};
}