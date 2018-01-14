#include "Tool.h"
#include <iostream>
#include <cassert>

double Engine::Tool::Lua::_GetNumberFromTableByKey(lua_State & io_luaState, std::string i_Key)
{
	double value = 0.0;

	if (!lua_istable(&io_luaState, -1))
	{
		std::cerr << "The top of LuaState must be a table " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;
		assert(false);
		return value;
	}


	lua_pushstring(&io_luaState, i_Key.c_str());
	lua_gettable(&io_luaState, -2);

	if (lua_isnumber(&io_luaState, -1))
	{
		value = lua_tonumber(&io_luaState, -1);
	}
	else
	{
		std::cerr << "The value at \"" << i_Key << "\" must be a number " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;
		assert(false);
	}

	lua_pop(&io_luaState, 1);

	return value;
}

std::string Engine::Tool::Lua::_GetStringFromTableByKey(lua_State & io_luaState, std::string i_Key)
{
	std::string result;

	if (!lua_istable(&io_luaState, -1))
	{
		std::cerr << "The top of LuaState must be a table " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;

		assert(false);

		return result;
	}


	lua_pushstring(&io_luaState, i_Key.c_str());
	lua_gettable(&io_luaState, -2);

	if (lua_isstring(&io_luaState, -1))
	{
		result = lua_tostring(&io_luaState, -1);
	}
	else
	{
		std::cerr << "The value at \"" << i_Key << "\" must be a number " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;
		assert(false);
	}

	lua_pop(&io_luaState, 1);

	return result;
}

void Engine::Tool::Debug::LOG(std::string message)
{
#if  _DEBUG
	std::cout << "\n" << message << std::endl;
#endif //  _DEBUG
}

void Engine::Tool::Debug::_Assert(int condition, std::string message, std::string file, int line)
{
	#if  _DEBUG

	if (condition == false)
	{
		std::cout << "\n" << message << std::endl;
		std::cout << file << " " << line << std::endl;
		__debugbreak();
	}
	#endif //  _DEBUG
}
