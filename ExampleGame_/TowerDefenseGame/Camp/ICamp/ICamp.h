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
	class ICamp
	{
	public:

		inline ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName);
		virtual inline ~ICamp();

		virtual inline void _RunCommand();

	protected:

		Engine::Asset::GameObject* m_GameObject;

		std::string m_SpriteName;

	private:

	};
}

#include "ICamp_inline.h"