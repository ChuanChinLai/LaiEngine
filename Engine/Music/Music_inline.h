#pragma once

#include "Music.h"
#include <cassert>

namespace Engine
{
	namespace Asset
	{
		inline Music::Music() : m_pMusic(nullptr)
		{

		}

		inline Music::~Music()
		{
			_Free();
		}

		inline bool Music::_Load(std::string i_Name)
		{
			m_pMusic = Mix_LoadMUS(i_Name.c_str());

			assert(m_pMusic != nullptr);

			return true;
		}

		inline bool Music::_IsLoaded()
		{
			return m_pMusic != nullptr;
		}

		inline void Music::_Play(int i_Loops)
		{
			if (m_pMusic != nullptr)
			{
				Mix_PlayMusic(m_pMusic, i_Loops);
			}
		}

		inline void Music::_Free()
		{
			if (m_pMusic != nullptr)
			{
				Mix_FreeMusic(m_pMusic);
				m_pMusic = nullptr;
			}
		}
	}
}
