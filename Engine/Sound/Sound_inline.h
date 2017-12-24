#pragma once

#include "Sound.h"
#include <iostream>
#include <cassert>

namespace Engine
{
	namespace Asset
	{
		inline Sound::Sound() : m_pSound(nullptr)
		{

		}

		inline Sound::~Sound()
		{
			_Release();
		}

		inline bool Sound::_Load(std::string i_Name)
		{
			m_pSound = Mix_LoadWAV(i_Name.c_str());

			assert(m_pSound != nullptr);

			return true;
		}

		inline bool Sound::_IsLoaded()
		{
			return m_pSound != nullptr;
		}

		inline int Sound::_Play(int i_Loops)
		{
			return (m_pSound != nullptr) ? Mix_PlayChannel(-1, m_pSound, i_Loops) : -1;
		}

		inline void Sound::_Release()
		{
			if (m_pSound != nullptr)
			{
				Mix_FreeChunk(m_pSound);
				m_pSound = nullptr;
			}
		}
	}
}