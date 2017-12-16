#pragma once

#include <Engine\GameEngine\GameEngine.h>

namespace Engine
{
	class GameDemo : public GameEngine
	{
	public:

		bool _Init()	override;
		void _Update()	override;
		void _Free()	override;
	};
}