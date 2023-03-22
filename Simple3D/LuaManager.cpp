#include <iostream>

#include "LuaManager.h"

const char* LuaTypeEnumToString(int lua_type)
{
	switch (lua_type)
	{
	case LUA_TNONE:
		return "none";
	case LUA_TNIL:
		return "nil";
	case LUA_TBOOLEAN:
		return "boolean";
	case LUA_TLIGHTUSERDATA:
		return "lightuserdata";
	case LUA_TNUMBER:
		return "number";
	case LUA_TSTRING:
		return "string";
	case LUA_TTABLE:
		return "table";
	case LUA_TFUNCTION:
		return "function";
	case LUA_TUSERDATA:
		return "userdata";
	case LUA_TTHREAD:
		return "thread";
	default:
		return "(unknown type)";
	}
}

void Simple3D::LuaManager::InitializeNewState()
{
	lua_state = luaL_newstate();
	luaL_openlibs(lua_state);
}

void Simple3D::LuaManager::OnApplicationExit()
{
	lua_close(lua_state);
}

void Simple3D::LuaManager::LoadFile(const char* filename)
{
	luaL_loadfile(lua_state, filename);
}

void Simple3D::LuaManager::LoadString(const char* code)
{
	luaL_dostring(lua_state, code);
}

int Simple3D::LuaManager::CallFunction(const char* function_name)
{
	int type_of_obj = lua_getglobal(lua_state, function_name);
	if (type_of_obj != LUA_TFUNCTION)
	{
		std::cout << function_name << " is not a function, but is an object of type " << LuaTypeEnumToString(type_of_obj) << "\n";
		return LUA_ERRRUN;
	}
	return lua_pcall(lua_state, 0, 1, 0);
}

int Simple3D::LuaManager::GetMemoryUsed()
{
	return lua_gc(lua_state, LUA_GCCOUNT);
}


