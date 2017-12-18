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

			virtual inline void _Init()
			{
				std::cout << "Init " << m_Name << std::endl;
			};

			virtual inline void _Update() 
			{
				std::cout << "Update " << m_Name << std::endl;
			};

			virtual inline void _Display()
			{
				std::cout << "Display " << m_Name << std::endl;
			}

			virtual inline void _Release()
			{
				std::cout << "Release " << m_Name << std::endl;
			};

			inline void SetName(std::string i_Name);
			inline std::string ToString();

		protected:
			SceneManager* m_pSceneManager;
			std::string m_Name;
		};
	}
}

#include "IGameScene_inline.h"