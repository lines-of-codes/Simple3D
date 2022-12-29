#pragma once

#include <iostream>

#include <raylib.h>
#include <fmt/core.h>

#include "Vector2Int.h"

namespace Simple3D
{
	struct WindowInfo
	{
		std::string window_title = "Untitled";
		unsigned short window_width;
		unsigned short window_height;
		Vector2Int window_pos = { 100, 100 };
		unsigned short targetfps = 60;

		WindowInfo()
		{
			window_width = 800;
			window_height = 600;
		}

		WindowInfo(uint8_t new_window_width, uint8_t new_window_height)
		{
			window_width = new_window_width;
			window_height = new_window_height;
		}

		std::string ToString()
		{
			return fmt::format(
				"window_size: ({}, {}), window_pos: ({}, {}), targetfps: {}", 
				window_width, window_height, 
				window_pos.x, window_pos.y, 
				targetfps);
		}
	};
}
