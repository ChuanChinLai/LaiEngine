#pragma once

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	class Color;

	namespace Asset
	{
		struct Component_Renderable
		{
			Component_Renderable() : pTexture(nullptr), w(0), h(0)
			{

			}

			SDL_Texture*  pTexture;

			int w;
			int h;
		};

		class GameObject
		{
		public:
			
			Math::Vector4D<float> m_Position;
		};


		class TextObject : public GameObject
		{
		public:

			TextObject();
			~TextObject();

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			Component_Renderable m_RenderComponent;
		};

		class SpriteObject : public GameObject
		{
		public:

			SpriteObject();
			~SpriteObject();

			bool _Create(std::string i_FilePath);
			void _Release();

			Component_Renderable m_RenderComponent;
		};

	}
}
