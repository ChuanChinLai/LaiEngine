#pragma once

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	namespace Asset
	{
		struct Component_Renderable
		{
			Component_Renderable() : pRenderer(nullptr), pTexture(nullptr), w(0), h(0)
			{

			}

			SDL_Renderer* pRenderer;
			SDL_Texture*  pTexture;

			int w;
			int h;
		};

		class GameObject
		{
		protected:
			
			Math::Vector4D<int> m_Position;
		};


		class TextObject : public GameObject
		{
		public:

			TextObject();
			~TextObject();

			bool _Create(std::string i_Text, SDL_Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			Component_Renderable m_RenderComponent;
		};

	}
}
