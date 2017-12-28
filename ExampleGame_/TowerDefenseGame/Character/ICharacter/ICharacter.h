#pragma once

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

		Engine::Asset::SpriteObject* _GetGameObject();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;
	private:
	};
}