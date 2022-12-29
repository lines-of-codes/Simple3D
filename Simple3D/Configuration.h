#pragma once

#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

#include "WindowInfo.h"

using json = nlohmann::json;

namespace Simple3D
{
	class Configuration
	{
	public:
		Configuration();

		void LoadConfigurationFromFile(const char* filename);
		void LoadConfigurationFromJson(json data);
		WindowInfo window_info;
		std::map<std::string, std::string> additional_configuration;
	};
}

