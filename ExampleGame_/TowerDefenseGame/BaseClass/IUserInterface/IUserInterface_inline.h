#pragma once

#include "IUserInterface.h"

inline void Gameplay::IUserInterface::_Show()
{
	m_bActive = true;
}

inline void Gameplay::IUserInterface::_Hide()
{
	m_bActive = false;
}

inline bool Gameplay::IUserInterface::_IsVisible()
{
	return m_bActive;
}
