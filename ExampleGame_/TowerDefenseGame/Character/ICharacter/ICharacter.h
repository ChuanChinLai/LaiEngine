#pragma once

#include <Engine\Math\Vector4D.h>

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

		virtual void _Init()	= 0;
		virtual void _Update()	= 0;
		virtual void _Release() = 0;

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);

		Engine::Asset::SpriteObject* _GetGameObject();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;

	private:
	};
}