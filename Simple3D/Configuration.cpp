#include "Configuration.h"

Simple3D::Configuration::Configuration()
{
	window_info = WindowInfo();
	additional_configuration = std::map<std::string, std::string>();
}

void Simple3D::Configuration::LoadConfigurationFromFile(const char* filename)
{
	std::ifstream f(filename);
	json data = json::parse(f);
	LoadConfigurationFromJson(data);
}

void Simple3D::Configuration::LoadConfigurationFromJson(json data)
{
	if (data.contains("windowInfo"))
	{
		json data_window_info = data["windowInfo"];
		std::cout << data_window_info << std::endl;
		window_info.window_width = data_window_info["windowWidth"];
		window_info.window_height = data_window_info["windowHeight"];
		window_info.window_title = data_window_info["windowTitle"];
	}
}
