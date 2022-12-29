#include "LuaManager.h"

void Simple3D::LuaManager::InitializeNewState()
{
	lua_state = luaL_newstate();
}

void Simple3D::LuaManager::LoadFile(const char* filename)
{
	luaL_loadfile(lua_state, filename);
}

void Simple3D::LuaManager::CallFunction(const char* function_name)
{
	lua_getglobal(lua_state, function_name);
	lua_pcall(lua_state, 0, 0, 0);
}

int Simple3D::LuaManager::GetMemoryUsed()
{
	return lua_gc(lua_state, LUA_GCCOUNT);
}


