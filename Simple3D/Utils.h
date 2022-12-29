#pragma once

#include <raylib.h>

#include "LuaManager.h"

namespace Simple3D
{
	struct SystemInstances
	{
		LuaManager* lua_manager;

		inline SystemInstances()
		{
			lua_manager = nullptr;
		}

		inline SystemInstances(LuaManager* new_lua_manager)
		{
			lua_manager = new_lua_manager;
		}
	};
}

inline Rectangle CreateNewRectangle(float x, float y, short width, short height)
{
	Rectangle rect = Rectangle();
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return rect;
}

inline Rectangle CreateNewRectangle(Rectangle parent, float x, float y, short width, short height)
{
	Rectangle rect = CreateNewRectangle(x, y, width, height);
	rect.x += parent.x;
	rect.y += parent.y;
	return rect;
}
