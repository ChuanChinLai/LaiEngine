#pragma once

#include "Component.h"

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>

#include <string>
#include <unordered_map>

namespace Engine
{
	class Color;

	namespace Asset
	{
		enum Alignment
		{
			Left,
			Right,
			Center,
			Up,
			Down,
		};

		class Component;
		class Component_Renderable;

		class GameObject
		{
		public:
			
			virtual ~GameObject();

			Math::Vector4D<float> m_Position;

			template<typename T>
			inline void _AddComponent();

			template<typename T>
			inline T* _GetComponent();

		private:

			std::unordered_map<Component::TYPE, Component*> m_Components;
		};


		class TextObject : public GameObject
		{
		public:

			TextObject();
			~TextObject();

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			inline Component_Renderable* _GetComponent_Renderable();

		private:

			Component* m_pRenderComponent;
		};

		class SpriteObject : public GameObject
		{
		public:

			SpriteObject();
			~SpriteObject();

			bool _Create(std::string i_FilePath);
			void _Release();

			inline Component_Renderable* _GetComponent_Renderable();

		private:
			Component_Renderable* m_pRenderComponent;
		};
	}
}

#include "GameObject_inline.h"