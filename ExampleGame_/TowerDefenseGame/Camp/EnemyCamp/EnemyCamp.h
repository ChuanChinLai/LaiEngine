#pragma once

#include <ExampleGame_\TowerDefenseGame\Camp\ICamp\ICamp.h>

namespace Gameplay
{
	class EnemyCamp : public ICamp
	{
	public:

		EnemyCamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName);
		~EnemyCamp();

		virtual void _RunCommand() override;

	private:

		float		m_Time;
		const float m_SpawnTime = 2.0f;
	};
}