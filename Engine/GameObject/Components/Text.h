#pragma once

#include "Component.h"

namespace Engine
{
	namespace Component
	{
		class Text : public ObjectComponent
		{
		public:

			Text(GameObject* i_GameObject);
			~Text();

			virtual void _Update() override;

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();
			void _SetAlignment(Engine::GameObject::Alignment i_xType, Engine::GameObject::Alignment i_yType);

			inline SDL_Texture * _GetTexture();

			int w;
			int h;

		private:

			Engine::GameObject::Alignment x_align = Engine::GameObject::Alignment::Center;
			Engine::GameObject::Alignment y_align = Engine::GameObject::Alignment::Center;

			SDL_Texture * pTexture;
		};
	}
}

#include "Text_inline.h"