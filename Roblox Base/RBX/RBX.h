#pragma once 
#include "offsets/offsets.h"
#include "driver/driver.h"
#include "RBX/math/math.h"
#include <cstdint>
#include <vector>
#include <windows.h>
#include <iostream>
#include <chrono>

namespace RBX {
    namespace Workspace {     
        std::vector<std::uint64_t> GetChildren(uintptr_t instance);
        std::uint64_t FindFirstChild(uintptr_t instance, const std::string& name);
        std::uint64_t FindFirstChildOfClass(uintptr_t instance, const std::string& className);
        std::uint64_t WaitForChild(const std::string& name, std::chrono::milliseconds timeout);
        std::uint64_t GetFakeDataModel();
        std::uint64_t GetDataModel();
        std::uint64_t GetWorkspaceToWorld();
        std::uint64_t GetWorkspace();
        std::uintptr_t GetPlayers();
        float GetClockTime();
        int GetDataModelPrimitiveCount();
    }

    namespace Graphics {
        std::uint64_t GetVisualEngine();
        std::uintptr_t GetVisualEnginePointer();
        RBX::Matrix3x3 GetViewMatrix();
    }

    namespace Players {        
        std::uint64_t GetLocalPlayer();
        std::vector<std::uint64_t> GetPlayerList();
        std::uint64_t GetCharacter(std::uint64_t playerAddress);
        float GetHealth(std::uint64_t humanoid);
        float GetMaxHealth(std::uint64_t humanoid);
        float GetWalkSpeed(std::uint64_t humanoid);
        float GetJumpPower(std::uint64_t humanoid);
        void SetWalkSpeed(std::uint64_t humanoid, float value);
        void SetJumpPower(std::uint64_t humanoid, float value);
        int GetPlayerTeamColor(std::uint64_t playerAddress);
        std::string GetPlayerName(std::uint64_t playerAddress);
        std::string GetDisplayName(std::uint64_t playerAddress);
    }

    namespace Camera {        
        std::uint64_t GetCamera();
        RBX::Vector3 GetPosition(std::uint64_t cameraAddress);
        RBX::Matrix4x4 GetViewMatrix(std::uint64_t cameraAddress);
        float GetCameraFOV(std::uint64_t cameraAddress);
        void SetCameraFOV(std::uint64_t cameraAddress, float value);
        RBX::Matrix3x3 GetRotation(std::uint64_t cameraAddress);
        void SetRotation(std::uint64_t cameraAddress, const RBX::Matrix3x3& rotation);
    }

    namespace Lighting {
        std::uint64_t GetLighting();
        void SetBrightness(int value);
        void SetFogStart(int value);
        void SetFogEnd(int value);
        void SetAmbience(const RBX::Vector3& color);
        void SetColorShiftTop(const RBX::Vector3& color);
        void SetColorShiftBottom(const RBX::Vector3& color);
    }

    namespace Gui {       
        void ClickButton(std::uint64_t guiElement);
        void SetText(std::uint64_t guiElement, const std::string& text);
        std::string GetText(std::uint64_t guiElement);
    }

    namespace Misc {       
        float GetPing();
        void TeleportPlayer(std::uint64_t player, const RBX::Vector3& pos);
        void WriteCFrame(std::uint64_t part, const RBX::CFrame& cf);
        void WritePosition(std::uint64_t part, const RBX::Vector3& pos);
    }

}