#pragma once

#include <string>
#include <iostream>

namespace Engine
{
	namespace Resource
	{
		class SceneManager;

		class IGameScene
		{
		public:

			IGameScene(SceneManager* i_pSceneManager);

			void SubmitBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);


			virtual void _Init() = 0;
			virtual void _Update() = 0;
			virtual void _Release() = 0;
			virtual void _SubmitDataToBeRendered() = 0;
				
			inline void SetName(std::string i_Name);
			inline std::string ToString();

		protected:
			SceneManager* m_pSceneManager;
			std::string m_Name;
		};
	}
}

#include "IGameScene_inline.h"