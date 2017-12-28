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

	protected:
		Engine::Asset::SpriteObject* m_GameObject;
	private:
	}
}