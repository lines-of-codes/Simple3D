#pragma once

#include <lua.hpp>

namespace Simple3D
{
	class LuaManager
	{
	public:
		void InitializeNewState();
		/// <summary>
		/// Do some clean up.
		/// </summary>
		void OnApplicationExit();
		void LoadFile(const char* filename);
		void LoadString(const char* code);
		int CallFunction(const char* function_name);
		/// <summary>
		/// Gets the current amount of memory used by lua in kbytes.
		/// </summary>
		/// <returns>How many kbytes is in use by the lua interpreter</returns>
		int GetMemoryUsed();

	private:
		lua_State* lua_state;
	};
}
