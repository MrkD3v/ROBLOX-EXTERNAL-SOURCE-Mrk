#pragma once
#include <cstdint>

namespace Offsets { // I labeled these's for what you have to read/write to them as.

    namespace Graphics {
        inline constexpr uintptr_t VisualEnginePointer = 0x6E10210;       // uintptr_t
        inline constexpr uintptr_t VisualEngine = 0x10;                   // uintptr_t / struct
        inline constexpr uintptr_t VisualEngineToDataModel1 = 0x700;      // uintptr_t
        inline constexpr uintptr_t VisualEngineToDataModel2 = 0x1C0;      // uintptr_t
        inline constexpr uintptr_t ViewMatrix = 0x4B0;                     // float[16] or struct
        inline constexpr uintptr_t Camera = 0x450;                        // uintptr_t / Camera object
        inline constexpr uintptr_t CameraMaxZoomDistance = 0x2C8;         // float
        inline constexpr uintptr_t CameraMinZoomDistance = 0x2CC;         // float
        inline constexpr uintptr_t CameraMode = 0x2D0;                     // int
        inline constexpr uintptr_t CameraPos = 0x124;                      // Vector3 struct
        inline constexpr uintptr_t CameraRotation = 0x100;                 // CFrame struct
        inline constexpr uintptr_t CameraSubject = 0xF0;                   // uintptr_t
        inline constexpr uintptr_t CameraType = 0x160;                     // int
        inline constexpr uintptr_t FOV = 0x168;                             // float
        inline constexpr uintptr_t FogColor = 0x104;                        // Vector3 / Color3
        inline constexpr uintptr_t FogStart = 0x140;                        // float
        inline constexpr uintptr_t FogEnd = 0x13C;                          // float
        inline constexpr uintptr_t SkyboxBk = 0x108;                        // uintptr_t
        inline constexpr uintptr_t SkyboxDn = 0x130;                        // uintptr_t
        inline constexpr uintptr_t SkyboxFt = 0x158;                        // uintptr_t
        inline constexpr uintptr_t SkyboxLf = 0x180;                        // uintptr_t
        inline constexpr uintptr_t SkyboxRt = 0x1A8;                        // uintptr_t
        inline constexpr uintptr_t SkyboxUp = 0x1D0;                        // uintptr_t
        inline constexpr uintptr_t OutdoorAmbient = 0x110;                  // Vector3
    }

    namespace Instance {
        inline constexpr uintptr_t Children = 0x68;
        inline constexpr uintptr_t Name = 0x88;
        inline constexpr uintptr_t ClassDescriptor = 0x18; 
        inline constexpr uintptr_t ClassDescriptorToClassName = 0x8;
    }

    namespace Lua {
        inline constexpr uintptr_t ScriptContext = 0x3D0;                   // uintptr_t
        inline constexpr uintptr_t LocalScriptByteCode = 0x1B0;             // uintptr_t
        inline constexpr uintptr_t LocalScriptBytecodePointer = 0x10;       // uintptr_t
        inline constexpr uintptr_t LocalScriptHash = 0x1C0;                 // uint64_t
        inline constexpr uintptr_t ModuleScriptByteCode = 0x158;            // uintptr_t
        inline constexpr uintptr_t ModuleScriptBytecodePointer = 0x10;      // uintptr_t
        inline constexpr uintptr_t ModuleScriptHash = 0x170;                // uint64_t
    }

    namespace Players {
        inline constexpr uintptr_t LocalPlayer = 0x128;                     // uintptr_t
        inline constexpr uintptr_t PlayerMouse = 0xC98;                     // uintptr_t
        inline constexpr uintptr_t PlayerConfigurerPointer = 0x708FAB8;    // uintptr_t
        inline constexpr uintptr_t Team = 0x258;                             // uintptr_t
        inline constexpr uintptr_t TeamColor = 0xD8;                        // uintptr_t / Color3
        inline constexpr uintptr_t UserId = 0x280;                           // int
        inline constexpr uintptr_t DisplayName = 0x118;                     // uintptr_t / string
        inline constexpr uintptr_t Name = 0x88;                              // uintptr_t / string
    }

    namespace Workspace {
        inline constexpr uintptr_t Workspace = 0x180;                       // uintptr_t
        inline constexpr uintptr_t WorkspaceToWorld = 0x3D8;                // uintptr_t
        inline constexpr uintptr_t Gravity = 0x998;                          // float
        inline constexpr uintptr_t GameLoaded = 0x6B0;                       // bool
        inline constexpr uintptr_t ClockTime = 0x1C0;                         // float
        inline constexpr uintptr_t DataModelPrimitiveCount = 0x410;          // int
        inline constexpr uintptr_t FakeDataModelPointer = 0x70B1EF8;         // uintptr_t
        inline constexpr uintptr_t FakeDataModelToDataModel = 0x1C0;         // uintptr_t
        inline constexpr uintptr_t DataModelDeleterPointer = 0x70B1F00;      // uintptr_t
        inline constexpr uintptr_t LocalPlayer = 0x128;                       // uintptr_t
        inline constexpr uintptr_t WorkspaceToRenderView = 0x1D8;            // uintptr_t
    }

    namespace Humanoid {
        inline constexpr uintptr_t Health = 0x19C;                             // int
        inline constexpr uintptr_t MaxHealth = 0x1BC;                          // int
        inline constexpr uintptr_t WalkSpeed = 0x1DC;                           // float
        inline constexpr uintptr_t JumpPower = 0x1B8;                           // float
        inline constexpr uintptr_t HipHeight = 0x1A8;                           // float
        inline constexpr uintptr_t HumanoidState = 0x870;                       // uintptr_t
        inline constexpr uintptr_t HumanoidStateId = 0x20;                     // int
        inline constexpr uintptr_t HumanoidDisplayName = 0xD8;                 // uintptr_t
    }

    namespace Physics {
        inline constexpr uintptr_t Anchored = 0x2E5;                            // bool / uint8_t mask
        inline constexpr uintptr_t AnchoredMask = 0x2;                           // uint8_t
        inline constexpr uintptr_t CanCollide = 0x2E5;                           // bool / uint8_t mask
        inline constexpr uintptr_t CanCollideMask = 0x8;                          // uint8_t
        inline constexpr uintptr_t CanTouch = 0x2E5;                              // bool / uint8_t mask
        inline constexpr uintptr_t CanTouchMask = 0x10;                           // uint8_t
        inline constexpr uintptr_t Velocity = 0x160;                               // Vector3
        inline constexpr uintptr_t Position = 0x154;                               // Vector3
        inline constexpr uintptr_t Rotation = 0x138;                               // Vector3 / CFrame
        inline constexpr uintptr_t Dimensions = 0x720;                             // Vector3
        inline constexpr uintptr_t PartSize = 0x23C;                                // Vector3
    }

}
