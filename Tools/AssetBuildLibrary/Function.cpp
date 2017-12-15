#include <cstdlib>
#include <cassert>
#include <External\Lua\Includes.h>
#include <iostream>

namespace
{
	int ExampleFunction(lua_State* io_luaState);
	int ExamplePrint(lua_State* io_luaState);
}


int main(int i_argumentCount, char** i_arguments)
{
	int exitCode = EXIT_SUCCESS;

	// Create a new Lua state
	lua_State* luaState = nullptr;
	{
		luaState = luaL_newstate();
		if (!luaState)
		{
			exitCode = EXIT_FAILURE;
			goto OnExit;
		}
	}
	// Open the standard libraries
	luaL_openlibs(luaState);

	// Make the C/C++ functions available to the Lua state
	// (this sets the function as a global variable
	// using the name provided)
	{
		lua_register(luaState, "ExampleFunction", ExampleFunction);
		lua_register(luaState, "ExamplePrint", ExamplePrint);
	}

	// Load and run the Lua script that calls the functions
	{
		// If you set breakpoints in the registered C/C++ functions
		// before executing the Lua script you will be able to watch them get called
		const auto result = luaL_dofile(luaState, "AssetBuildFunctions.lua");
		if (result != LUA_OK)
		{
			const auto* const errorMessage = lua_tostring(luaState, -1);
			std::cerr << errorMessage << std::endl;
			lua_pop(luaState, 1);

			exitCode = EXIT_FAILURE;
			goto OnExit;
		}
	}

OnExit:

	if (luaState)
	{
		// If I haven't made any mistakes
		// there shouldn't be anything on the stack
		// regardless of any errors
		assert(lua_gettop(luaState) == 0);

		lua_close(luaState);
		luaState = NULL;
	}

	return exitCode;
}

namespace
{
	int ExampleFunction(lua_State* io_luaState)
	{
		// This function doesn't use any input parameters:
		std::cout << "This statement will be displayed when this function is called" << std::endl;

		// This function doesn't return any values:
		constexpr int returnValueCount = 0;
		return returnValueCount;
	}

	int ExamplePrint(lua_State* io_luaState)
	{
		// This function expects a single input parameter.

		// Every argument that the Lua script provides as input to the function
		// is available to us here in our C/C++ function
		// as values pushed on the stack in the provided lua_State.
		// These values have _positive_ indices.
		// For example, if a function were called from Lua like this:
		//	* SomeFunction( argument1, argument2, argument3 )
		// Then in the SomeFunction() C/C++ code argument1 would be index 1,
		// argument2 would be index 2, and argument3 would be index 3.

		// In the case of this specific function, then,
		// we expect that the caller has provided a single argument,
		// and that argument should be at index 1:
		const auto* const i_value = lua_tostring(io_luaState, 1);

		std::cout << "The input parameter to ExamplePrint() is " << i_value << std::endl;

		// This function doesn't return any values:
		constexpr int returnValueCount = 0;
		return returnValueCount;
	}
}