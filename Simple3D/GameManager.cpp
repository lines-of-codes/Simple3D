#include "GameManager.h"

Simple3D::GameManager::GameManager()
{
	camera_manager = CameraManager();
	lua_manager = LuaManager();
	sys = SystemInstances(&lua_manager);
#ifdef _DEBUG
	editor = std::nullopt;
#endif // _DEBUG
}

void Simple3D::GameManager::Init(Configuration* configuration)
{
	WindowInfo window_info = configuration->window_info;
	this->configuration = configuration;

	Init(window_info.window_width, window_info.window_height, window_info.window_title.c_str());
	SetWindowPosition(window_info.window_pos.x, window_info.window_pos.y);
	SetTargetFPS(window_info.targetfps);
}

void Simple3D::GameManager::Init(unsigned short windowWidth, unsigned short windowHeight, const char* title)
{
	InitWindow(windowWidth, windowHeight, title);
}

void Simple3D::GameManager::Run()
{
	SetCameraMode(camera_manager.current_camera, CAMERA_FREE);

	MainLoop();

	CloseWindow();
}

void Simple3D::GameManager::MainLoop()
{
#ifdef _DEBUG
	editor = Editor(configuration);
#endif // _DEBUG

	while (!WindowShouldClose())
	{
#ifdef _DEBUG
		if(editor.value().update_camera)
#endif
			UpdateCamera(&camera_manager.current_camera);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		BeginMode3D(camera_manager.current_camera);

		DrawCube({ 0, 0, 0 }, 2.5f, 2.5f, 2.5f, RED);
		DrawGrid(10, 5);
		
		EndMode3D();

#ifdef _DEBUG
		editor.value().Render(sys);
#endif // _DEBUG

		EndDrawing();
	}

	CloseWindow();
}
