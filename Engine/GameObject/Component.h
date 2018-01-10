#pragma once

#include <External\SDL2\Includes.h>

namespace Engine
{
	namespace Asset
	{
		class GameObject;

		enum Component_TYPE
		{

		};

		class Component
		{
		public:
			Component(GameObject* i_GameObject) : m_GameObject(i_GameObject)
			{

			}
			virtual ~Component()
			{

			}
			GameObject* m_GameObject;
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