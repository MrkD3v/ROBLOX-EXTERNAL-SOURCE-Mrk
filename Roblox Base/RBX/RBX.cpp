#pragma once
#include "rbx.h"
#include <vector>
#include <iostream>
#include "Globals/Globals.h"

std::uint64_t RBX::Workspace::GetFakeDataModel() {
    return read<std::uint64_t>(Base + Offsets::Workspace::FakeDataModelPointer);
}

std::uint64_t RBX::Workspace::GetDataModel() {
    return read<std::uint64_t>(Base + Offsets::Workspace::FakeDataModelToDataModel);
}

std::uint64_t RBX::Workspace::GetWorkspaceToWorld() {
    std::uint64_t workspacePointer = RBX::Workspace::GetDataModel();
    return read<std::uint64_t>(workspacePointer + Offsets::Workspace::WorkspaceToWorld);
}

std::uint64_t RBX::Workspace::GetWorkspace() {
    return read<std::uint64_t>(Base + Offsets::Workspace::Workspace);
}

int RBX::Workspace::GetDataModelPrimitiveCount() { // This might be wrong im not 100%
    return static_cast<int>(read<std::uint64_t>(Base + Offsets::Workspace::DataModelPrimitiveCount));
}

float RBX::Workspace::GetClockTime() {
    return read<float>(Base + Offsets::Workspace::ClockTime);
}

std::uint64_t RBX::Graphics::GetVisualEngine() {
    return read<std::uint64_t>(Base + Offsets::Graphics::VisualEngine);
}

/*
 This is just some info to help you out.
 To get players you need these 3 Functions
 GetChildren
 FindFirstChild
 FindFirstChildOfClass
 FindFirstChildOfClass is for getting the Player Services

 Example is :
   return RBX::Workspace::FindFirstChildOfClass("Players")
   or auto PlayerService = RBX::Workspace::FindFirstChildOfClass("Players")
   return PlayerService

   Dont say you made this cuz its literally a base with no features lol.
   
   This was made by Abyss
   If you wanna add me on discord its : get_local_entity - Feel free to dm me for help.
   My github is : https://github.com/luaraw
   My server is : https://discord.gg/XdcjCC7wq5
*/