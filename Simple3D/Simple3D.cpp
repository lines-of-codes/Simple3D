// Simple3D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Essentials.h"

using namespace nlohmann::literals;

int main()
{
    Simple3D::Configuration config = Simple3D::Configuration();
    config.LoadConfigurationFromJson({
        {
            "windowInfo", 
            {
                { "windowWidth", 1280 },
                { "windowHeight", 720 },
                { "windowTitle", "Test"}
            }
        }
    });
    std::cout << config.window_info.ToString() << std::endl;

    std::cout << "Hello World!\n";
    Simple3D::GameManager gm = Simple3D::GameManager();
    gm.LoadLuaCodeString("function OnLoad() print(\"Hello world from Lua!\") end");
    gm.Init(&config);
    gm.Run();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
