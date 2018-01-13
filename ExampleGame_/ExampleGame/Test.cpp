#include "Test.h"

#include <External\Lua\Includes.h>
#include <cassert>

bool _LoadCampDataFromLua(std::string i_FilePath)
{
	auto result = true;

	// Create a new Lua state
	lua_State* pLuaState = nullptr;
	{
		pLuaState = luaL_newstate();
		if (!pLuaState)
		{
			result = false;
			std::cerr << "Failed to create a new Lua state" << std::endl;
			goto OnExit;
		}
	}

	// Load the asset file as a "chunk",
	// meaning there will be a callable function at the top of the stack
	const auto stackTopBeforeLoad = lua_gettop(pLuaState);
	{
		const auto luaResult = luaL_loadfile(pLuaState, i_FilePath.c_str());
		if (luaResult != LUA_OK)
		{
			result = false;
			std::cerr << lua_tostring(pLuaState, -1) << std::endl;
			// Pop the error message
			lua_pop(pLuaState, 1);
			goto OnExit;
		}
	}
	// Execute the "chunk", which should load the asset
	// into a table at the top of the stack
	{
		constexpr int argumentCount = 0;
		constexpr int returnValueCount = LUA_MULTRET;	// Return _everything_ that the file returns
		constexpr int noMessageHandler = 0;
		const auto luaResult = lua_pcall(pLuaState, argumentCount, returnValueCount, noMessageHandler);
		if (luaResult == LUA_OK)
		{
			// A well-behaved asset file will only return a single value
			const auto returnedValueCount = lua_gettop(pLuaState) - stackTopBeforeLoad;
			if (returnedValueCount == 1)
			{
				// A correct asset file _must_ return a table
				if (!lua_istable(pLuaState, -1))
				{
					result = false;
					std::cerr << "Asset files must return a table (instead of a " <<
						luaL_typename(pLuaState, -1) << ")" << std::endl;
					// Pop the returned non-table value
					lua_pop(pLuaState, 1);
					goto OnExit;
				}
			}
			else
			{
				result = false;
				std::cerr << "Asset files must return a single table (instead of " <<
					returnedValueCount << " values)" << std::endl;
				// Pop every value that was returned
				lua_pop(pLuaState, returnedValueCount);
				goto OnExit;
			}
		}
		else
		{
			result = false;
			std::cerr << lua_tostring(pLuaState, -1) << std::endl;
			// Pop the error message
			lua_pop(pLuaState, 1);
			goto OnExit;
		}
	}

	// If this code is reached the asset file was loaded successfully,
	// and its table is now at index -1
	//	result = LoadTableValues(*luaState);

	// Pop the table
	lua_pop(pLuaState, 1);

OnExit:

	if (pLuaState)
	{
		// If I haven't made any mistakes
		// there shouldn't be anything on the stack,
		// regardless of any errors encountered while loading the file:
		assert(lua_gettop(pLuaState) == 0);

		lua_close(pLuaState);
		pLuaState = nullptr;
	}

	return result;
}