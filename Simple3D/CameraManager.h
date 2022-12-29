#pragma once

#include <iostream>
#include <vector>

#include <raylib.h>

namespace Simple3D
{
	class CameraManager
	{
	public:
		CameraManager();

		Camera3D current_camera;
		std::vector<Camera3D> registered_camera;
	private:
		Camera3D GetDefaultCamera() const;
	};
}
