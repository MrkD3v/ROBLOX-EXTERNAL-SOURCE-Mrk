#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

namespace RBX {
	namespace Globals {
		struct Instances {
			std::uint64_t FakeDatamodel;
			std::uint64_t Datamodel;
			std::uint64_t Workspace;
			std::uint64_t WorkspaceToWorld;
			std::uint64_t Players;
			std::uintptr_t TweenService;
			std::uintptr_t ClockTime;
			std::uintptr_t DatamodelCount;
		};
		Instances Instance;

		struct Aimbots {
			
		};
		Aimbots Aimbot;
		void CheckVariables();
	}
}