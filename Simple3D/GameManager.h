#pragma once

#include <iostream>
#include <optional>

#include <raylib.h>

#include "LuaManager.h"
#include "Configuration.h"
#include "CameraManager.h"
#include "Editor.h"

namespace Simple3D
{
	class GameManager
	{
	public:
		GameManager();

		/// <summary>
		/// Initializes the Window
		/// </summary>
		void Init(Configuration* configuration);
		/// <summary>
		/// Initializes the window
		/// </summary>
		/// <param name="windowWidth">The width of the window</param>
		/// <param name="windowHeight">The height of the window</param>
		/// <param name="title">The title of the window</param>
		void Init(unsigned short windowWidth, unsigned short windowHeight, const char* title);
		/// <summary>
		/// Loads a string of lua code. Should be called before GameManager.Init()
		/// </summary>
		/// <param name="code">The lua code</param>
		void LoadLuaCodeString(const char* code);
		/// <summary>
		/// Loads a lua file. Should be called before GameManager.Init()
		/// </summary>
		/// <param name="filename">The name of the file you're trying to load.</param>
		void LoadLuaFile(const char* filename);
		void Run();

		CameraManager camera_manager;
		SystemInstances sys;
	private:
		LuaManager lua_manager;
		Configuration* configuration;
#ifdef _DEBUG
		std::optional<Editor> editor;
#endif // _DEBUG

		void MainLoop();
	};
}
