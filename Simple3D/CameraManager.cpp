#include "CameraManager.h"

Simple3D::CameraManager::CameraManager()
{
	registered_camera = { GetDefaultCamera() };
	current_camera = registered_camera[0];
}

Camera3D Simple3D::CameraManager::GetDefaultCamera() const
{
	Camera3D camera = { 0 };
	camera.position = { 0.0f, 10.0f, 10.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	return camera;
}
