#pragma once

#include <External\SDL2\Includes.h>
#include <string>
#include <vector>
#include <iostream>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
		class TextObject;
		class SpriteObject;
	}


	class SceneManager;

	class IGameScene
	{
	public:

		struct sDataRequiredToRenderAFrame
		{
			SDL_Color BackgroundColor;
			std::vector<Engine::Asset::TextObject*>		TextObjects;
			std::vector<Engine::Asset::SpriteObject*> SpriteObjects;
		};


		IGameScene(SceneManager* i_pSceneManager);

		inline void SubmitBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
		inline void SubmitTextObject(Asset::TextObject* i_object);
		inline void SubmitSpriteObject(Asset::SpriteObject* i_object);


		virtual void _Init() = 0;
		virtual void _Update() = 0;
		virtual void _Release() = 0;
		virtual void _SubmitDataToBeRendered() = 0;

		sDataRequiredToRenderAFrame m_RenderedData;

	protected:
		SceneManager *	m_pSceneManager;
		std::string		m_Name;
	};
}

#include "IGameScene_inline.h"