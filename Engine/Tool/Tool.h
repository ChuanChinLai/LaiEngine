#pragma once

#include <External\Lua\Includes.h>
#include <string>

namespace Engine
{
	namespace Tool
	{
		namespace Debug
		{
			extern void LOG(std::string message);
			extern void _Assert(int condition, std::string message, std::string file, int line);
			#define ASSERT(a, b) _Assert(a, b, __FILE__, __LINE__)
		}

		namespace Lua
		{
			extern      double	_GetNumberFromTableByKey(lua_State& io_luaState, std::string i_Key);
			extern std::string	_GetStringFromTableByKey(lua_State& io_luaState, std::string i_Key);
		}
	}
}

