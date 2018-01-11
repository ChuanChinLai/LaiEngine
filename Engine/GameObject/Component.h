#pragma once

#include <Engine\Color\Color.h>

#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	namespace Asset
	{
		class GameObject;

		class Component
		{
		public:

			enum TYPE
			{
				Sprite,
				Text,
				Null,
			};

			inline Component(GameObject* i_GameObject);

			inline virtual ~Component();

			inline GameObject* _GetGameObject();
			inline TYPE		_GetType();

		protected:

			GameObject* m_GameObject;
			TYPE m_TYPE;
		};


		class Sprite : public Component
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

#include "Component_inline.h"