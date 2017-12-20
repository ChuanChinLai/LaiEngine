#pragma once

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
	class IGameScene;

	class SceneManager
	{
	public:

		struct sDataRequiredToRenderAFrame
		{
			SDL_Color BackgroundColor;
		};

		SceneManager() : m_pCurrentScene(nullptr), m_bRunBegin(false)
		{
			_SetBackgroundColor(255, 255, 255, 255);
		};

		~SceneManager();

		void _SetGameScene(IGameScene* i_Scene, std::string i_Name);
		void _SetGameScene(IGameScene* i_Scene);

		inline void		 _SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
		inline SDL_Color _GetBackgroundColor();

		void _Update();
		void _Render();
		void _Release();

	private:

		sDataRequiredToRenderAFrame m_RenderedData;

		IGameScene* m_pCurrentScene;
		bool 		m_bRunBegin;
	};
}

#include "SceneManager_inline.h"