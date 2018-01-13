#include "CampSystem.h"

#include <Engine\GameObject\GameObject.h>
#include <Engine\Tool\Tool.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Camp\SoldierCamp\SoldierCamp.h>
#include <ExampleGame_\TowerDefenseGame\Camp\EnemyCamp\EnemyCamp.h>

#include <iostream>
#include <cassert>



Gameplay::CampSystem::CampSystem(TowerDefenseGame * i_pTDGame) : IGameSystem(i_pTDGame)
{

}

void Gameplay::CampSystem::_Init()
{
	_LoadCampDataFromLua("Gameplay/CampData.lua");
}

void Gameplay::CampSystem::_Update()
{
	for (const auto Camp : m_SoldierCamps)
	{
		Camp.second->_RunCommand();
	}

	for (const auto Camp : m_EnemyCamps)
	{
		Camp.second->_RunCommand();
	}
}

void Gameplay::CampSystem::_Release()
{
	for (const auto Camp : m_SoldierCamps)
	{
		if (Camp.second != nullptr)
			delete Camp.second;
	}

	m_SoldierCamps.clear();

	for (const auto Camp : m_EnemyCamps)
	{
		if (Camp.second != nullptr)
			delete Camp.second;
	}

	m_EnemyCamps.clear();
}

void Gameplay::CampSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{

}

SDL_Scancode Gameplay::CampSystem::SoldierCampFactory(Soldier::TYPE emSoldier)
{
	SDL_Scancode CommandCode;

	switch (emSoldier)
	{
	case Soldier::S1:
		CommandCode = SDL_SCANCODE_Q;
		break;

	case Soldier::S2:
		CommandCode = SDL_SCANCODE_W;
		break;

	case Soldier::S3:
		CommandCode = SDL_SCANCODE_E;
		break;
	default:
		std::cout << "ERROR TYPE" << std::endl;
		assert(false);
		break;
	}
	return CommandCode;
}

bool Gameplay::CampSystem::_LoadCampDataFromLua(std::string i_FilePath)
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
			const auto returnedValueCount = lua_gettop(pLuaState);
			if (returnedValueCount == 1)
			{
				// A correct asset file _must_ return a table
				if (!lua_istable(pLuaState, -1))
				{
					result = false;
					std::cerr << "Asset files must return a table (instead of a " << luaL_typename(pLuaState, -1) << ")" << std::endl;
					// Pop the returned non-table value
					lua_pop(pLuaState, 1);
					goto OnExit;
				}
			}
			else
			{
				result = false;
				std::cerr << "Asset files must return a single table (instead of " << returnedValueCount << " values)" << std::endl;
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

	result = _LoadCampTableValues(*pLuaState);

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

bool Gameplay::CampSystem::_LoadCampTableValues(lua_State & io_luaState)
{
	bool result = true;

	if (!(result = _LoadSoldierCampTableValues(io_luaState)))
	{
		return result;
	}

	if (!(result = _LoadEnemyCampTableValues(io_luaState)))
	{
		return result;
	}

	return result;
}

bool Gameplay::CampSystem::_LoadSoldierCampTableValues(lua_State & io_luaState)
{
	bool result = true; 

	constexpr auto* const key = "SoldierCamps";
	lua_pushstring(&io_luaState, key);
	lua_gettable(&io_luaState, -2);

	if (!lua_istable(&io_luaState, -1))
	{
		std::cerr << "The value at \"" << key << "\" must be a table " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;
		goto OnExit;
	}

	//Load the Soldier Camp value;
	{
		const auto campCount = luaL_len(&io_luaState, -1);

		assert(campCount < Soldier::TYPE::TOTAL);

		for (int i = 1; i <= campCount; ++i)
		{
			lua_pushinteger(&io_luaState, i);
			lua_gettable(&io_luaState, -2);

			if (lua_istable(&io_luaState, -1))
			{
				Engine::Math::Vector4D<float> position;
				Gameplay::CharacterAttr* pAttributeData = new CharacterAttr();
				double value = 0.0f;

				//Position
				{
					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "X");
					position.x = static_cast<float>(value);

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "Y");
					position.y = static_cast<float>(value);
				}

				//Attribute
				{
					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "HP");
					pAttributeData->_SetHP(static_cast<float>(value));

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "ATK");
					pAttributeData->_SetATK(static_cast<float>(value));


					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "DEF");
					pAttributeData->_SetDEF(static_cast<float>(value));

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "SPEED");
					pAttributeData->_SetSpeed(static_cast<float>(value));
				}

				//Sprite Name
				std::string SpriteName = Engine::Tool::Lua::_GetStringFromTableByKey(io_luaState, "SpriteName");

				SoldierCamp* NewCamp = new SoldierCamp(position, SpriteName);
				NewCamp->_SetTowerDefenseGame(m_pTDGame);
				NewCamp->_SetAttributeData(pAttributeData);
				NewCamp->_SetCommandCode(SoldierCampFactory(static_cast<Soldier::TYPE>(i)));
				m_SoldierCamps[static_cast<Soldier::TYPE>(i)] = NewCamp;

			}
			lua_pop(&io_luaState, 1);
		}
	}

OnExit:

	//Pop the parameters table
	lua_pop(&io_luaState, 1);

	return result;
}

bool Gameplay::CampSystem::_LoadEnemyCampTableValues(lua_State & io_luaState)
{
	bool result = true;

	constexpr auto* const key = "EnemyCamps";
	lua_pushstring(&io_luaState, key);
	lua_gettable(&io_luaState, -2);

	if (!lua_istable(&io_luaState, -1))
	{
		std::cerr << "The value at \"" << key << "\" must be a table " "(instead of a " << luaL_typename(&io_luaState, -1) << ")" << std::endl;
		goto OnExit;
	}

	//Load the Soldier Camp value;
	{
		const auto campCount = luaL_len(&io_luaState, -1);

		assert(campCount < Enemy::TYPE::TOTAL);

		for (int i = 1; i <= campCount; ++i)
		{
			lua_pushinteger(&io_luaState, i);
			lua_gettable(&io_luaState, -2);

			if (lua_istable(&io_luaState, -1))
			{
				Engine::Math::Vector4D<float> position;
				Gameplay::CharacterAttr* pAttributeData = new CharacterAttr();
				double value = 0.0f;

				//Position
				{
					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "X");
					position.x = static_cast<float>(value);

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "Y");
					position.y = static_cast<float>(value);
				}

				//Attribute
				{
					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "HP");
					pAttributeData->_SetHP(static_cast<float>(value));

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "ATK");
					pAttributeData->_SetATK(static_cast<float>(value));


					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "DEF");
					pAttributeData->_SetDEF(static_cast<float>(value));

					value = Engine::Tool::Lua::_GetNumberFromTableByKey(io_luaState, "SPEED");
					pAttributeData->_SetSpeed(static_cast<float>(value));
				}

				//Sprite Name
				std::string SpriteName = Engine::Tool::Lua::_GetStringFromTableByKey(io_luaState, "SpriteName");

				EnemyCamp* NewCamp = new EnemyCamp(position, SpriteName);
				NewCamp->_SetTowerDefenseGame(m_pTDGame);
				NewCamp->_SetAttributeData(pAttributeData);
				m_EnemyCamps[static_cast<Enemy::TYPE>(i)] = NewCamp;

			}
			lua_pop(&io_luaState, 1);
		}
	}

OnExit:

	//Pop the parameters table
	lua_pop(&io_luaState, 1);

	return result;
}
