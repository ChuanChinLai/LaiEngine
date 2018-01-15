#pragma once

#include "Component.h"

namespace Engine
{
	namespace Component
	{
		class Sprite : public ObjectComponent
		{
		public:

			Sprite(GameObject* i_GameObject);
			~Sprite();

			bool _Create(std::string i_FilePath);
			void _Release();

			inline SDL_Texture * _GetTexture();

			int w;
			int h;

		private:
			SDL_Texture * pTexture;
		};
	}
}

#include "Sprite_inline.h"