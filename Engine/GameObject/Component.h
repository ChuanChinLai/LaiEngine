#pragma once

#include <External\SDL2\Includes.h>

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

			Component(GameObject* i_GameObject) : m_GameObject(i_GameObject), m_TYPE(TYPE::Null)
			{
				
			}
			virtual ~Component()
			{

			}
			GameObject* m_GameObject;

			TYPE _GetType()
			{
				return m_TYPE;
			}

		protected:

			TYPE m_TYPE;
		};


		class Sprite : public Component
		{
		public:

			Sprite(GameObject* i_GameObject) : Component(i_GameObject)
			{
				m_TYPE = TYPE::Sprite;
			}

			~Sprite()
			{

			}

			SDL_Texture*  pTexture;

			int w;
			int h;
		};


		class Text : public Component
		{
		public:

			Text(GameObject* i_GameObject) : Component(i_GameObject)
			{
				m_TYPE = TYPE::Text;
			}

			~Text()
			{

			}

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