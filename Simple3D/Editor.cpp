#include "Editor.h"

#ifdef _DEBUG
#include <algorithm>

#include <raygui.h>

std::string empty = "";

Simple3D::Editor::Editor(Configuration* configuration)
{
	GuiSetFont(LoadFont("./Resources/Montserrat-Bold.ttf"));
	GuiSetStyle(DEFAULT, TEXT_SIZE, 15);
	GuiSetStyle(CHECKBOX, TEXT_PADDING, 8);

	show_settings_button = CreateNewRectangle(50.0f, configuration->window_info.window_height - 80.0f, 30, 30);
	show_stats_button = CreateNewRectangle(90.0f, configuration->window_info.window_height - 80.0f, 60, 30);

	stats_window = CreateNewRectangle(configuration->window_info.window_width - 220.0f, 20.0f, 150.0f, 150.0f);
	stats_text = CreateNewRectangle(stats_window, 25, 25, 100, 100);

	unsigned short i = 0;
	for (std::map<const char*, unsigned short>::iterator iter = possible_keys.begin(); iter != possible_keys.end(); ++iter)
	{
		const char* key = iter->first;
		unsigned short value = iter->second;
		possible_keys_by_keycode.insert({ value, key });
	}
}

void Simple3D::Editor::Render(SystemInstances sys)
{
	update_camera = GuiCheckBox(update_camera_checkbox, "Update Camera", update_camera);
	
	if (GuiButton(show_settings_button, "#142#"))
		show_settings = !show_settings;

	if (GuiButton(show_stats_button, "Stats"))
		show_stats = !show_stats;

	if (show_settings)
	{
		show_settings = !GuiWindowBox(settings_window, "Settings");
		active_tab_index = (SettingsTab)GuiToggleGroup(settings_tabs, "Keybinds;About", (unsigned short)active_tab_index);

		if (active_tab_index == SettingsTab::ABOUT)
		{
			GuiDrawText("Simple3D, Making the 3D world simpler.\nPowered by raysan5/raylib (zlib/libpng license),\nraysan5/raygui (zlib/libpng license), lua (MIT license),\nnlohmann/json (MIT license), fmtlib/fmt", about_text, TEXT_ALIGN_LEFT, BLACK);
		}
		else if (active_tab_index == SettingsTab::KEYBINDS)
		{
			keybind_list_active = (Keybinds)GuiListView(keybind_list_view, "Pan;Rotate;Smooth Zoom", &keybind_list_scroll_index, (unsigned short)keybind_list_active);
			
			GuiGroupBox(selected_key_block, "Key Information");

			std::string keyskey;

			switch (keybind_list_active)
			{
			case Keybinds::PAN:
				GuiDrawText("Pan", selected_key_label, TEXT_ALIGN_LEFT, BLACK);
				keyskey = "pan";
				break;
			case Keybinds::ROTATE:
				GuiDrawText("Rotate", selected_key_label, TEXT_ALIGN_LEFT, BLACK);
				keyskey = "rotate";
				break;
			case Keybinds::SMOOTH_ZOOM:
				GuiDrawText("Smooth Zoom", selected_key_label, TEXT_ALIGN_LEFT, BLACK);
				keyskey = "smooth_zoom";
				break;
			}
			ShortcutFunctionKey key = keys[keyskey];

			GuiDrawText(((key.shift ? std::string("LShift + ") : empty) + (key.ctrl ? std::string("LCTRL + ") : empty) + (key.alt ? std::string("LALT + ") : empty) + possible_keys_by_keycode[key.key]).c_str(), pressed_key_label, TEXT_ALIGN_LEFT, BLACK);
		}
	}

	if (show_stats)
	{
		GuiDrawText(fmt::format("FPS: {}\nLua's Memory Usage: {}", GetFPS(), sys.lua_manager->GetMemoryUsed()).c_str(), stats_text, TEXT_ALIGN_LEFT, BLACK);
	}
}
#endif
