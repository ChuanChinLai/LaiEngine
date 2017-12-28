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

		Engine::Asset::SpriteObject* _GetGameObject();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;
	private:
	};
}