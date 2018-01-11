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

			SDL_Texture*  pTexture;

			int w;
			int h;
		};


		class Text : public Component
		{
		public:

			Text(GameObject* i_GameObject);
			~Text();

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			SDL_Texture*  pTexture;
			int w;
			int h;
		};


		class Component_Renderable : public Component
		{
		public:
			Component_Renderable(GameObject* i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
			{

			}

			~Component_Renderable()
			{

			}

			SDL_Texture*  pTexture;

			int w;
			int h;
		};
	}
}

#include "Component_inline.h"