#pragma once

#include <External\Lua\Includes.h>
#include <string>

namespace Engine
{
	namespace Tool
	{
		namespace Debug
		{
			extern void Log(std::string i_Message);
			extern void Log(bool i_Condition, std::string i_Message);
		}

		namespace Lua
		{
			extern      double	_GetNumberFromTableByKey(lua_State& io_luaState, std::string i_Key);
			extern std::string	_GetStringFromTableByKey(lua_State& io_luaState, std::string i_Key);
		}
	}
}