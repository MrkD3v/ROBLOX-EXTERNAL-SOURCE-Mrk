#include "Driver/Driver.h"
#include "Offsets/Offsets.h"
#include "RBX/RBX.h"
#include "RBX/Globals/Globals.h"
#include "RBX/Owen/Owen.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

/*
   This was made by Abyss
   If you wanna add me on discord its : get_local_entity - Feel free to dm me for help.
   My github is : https://github.com/luaraw
   My server is : https://discord.gg/XdcjCC7wq5
*/

void SetConsoleFont() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_FONT_INFOEX cfi = {};
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;
    cfi.dwFontSize.Y = 12;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Terminal");

    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void Playerlist() {
    auto playersService = RBX::Workspace::GetPlayers();
    if (!playersService) {
        std::cout << "Players service not found!\n";
        return;
    }

    // read children of Players service
    auto childrenArray = read<std::uint64_t>(playersService + Offsets::Instance::Children);
    auto numPlayers = read<std::uint64_t>(childrenArray + 0x10);  // number of players
    auto dataPtr = read<std::uint64_t>(childrenArray + 0x8);      // pointer to array

    std::cout << "Players list:\n";

    for (std::uint64_t i = 0; i < numPlayers; i++) {
        auto player = read<std::uint64_t>(dataPtr + i * 0x8);
        if (!player) continue;

        char nameBuffer[128] = {};
        read_array(player + Offsets::Instance::Name, nameBuffer, sizeof(nameBuffer));

        std::cout << "- " << nameBuffer << "\n";
    }
}


int main() {
    SetConsoleFont();

    if (!DriverInitialize()) {
        std::cout << "Failed to find Roblox process" << std::endl;
        return 1;
    }
    RBX::Globals::CheckVariables();
    std::cout << "FakeDatamodel: 0x" << std::hex << RBX::Globals::Instance.FakeDatamodel << std::endl;
    std::cout << "DatamodelDeleter: 0x" << std::hex << RBX::Globals::Instance.Datamodel << std::endl;
    std::cout << "Workspace: 0x" << std::hex << RBX::Globals::Instance.Workspace << std::endl;
    std::cout << "WorkspaceToWorld: 0x" << std::hex << RBX::Globals::Instance.WorkspaceToWorld << std::endl;
    std::cout << "DataModelPrimitiveCount: 0x" << std::hex << RBX::Globals::Instance.DatamodelCount << std::endl;
    Playerlist();
    std::cin.get();
}
