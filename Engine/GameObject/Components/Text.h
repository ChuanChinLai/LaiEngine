#pragma once

#include "Component.h"

namespace Engine
{
	namespace Asset
	{
		class Text : public Component
		{
		public:

			Text(GameObject* i_GameObject);
			~Text();

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			inline SDL_Texture * _GetTexture();

			int w;
			int h;

		private:
			SDL_Texture * pTexture;
		};
	}
}

#include "Text_inline.h"