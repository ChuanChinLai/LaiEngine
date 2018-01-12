#pragma once

#include <ExampleGame_\TowerDefenseGame\Camp\ICamp\ICamp.h>

namespace Gameplay
{
	class EnemyCamp : public ICamp
	{
	public:

		EnemyCamp(Engine::Asset::GameObject* i_GameObject);
		~EnemyCamp();

		virtual void _RunCommand() override;

	private:

		float m_Time = 0;
		const float m_SpawnTime = 2.0f;
	};
}