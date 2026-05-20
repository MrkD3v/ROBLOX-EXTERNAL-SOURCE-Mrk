#pragma once
#include "RBX/Globals/Globals.h"
#include "RBX/RBX.h"

void RBX::Globals::CheckVariables() {
	RBX::Globals::Instance.FakeDatamodel = RBX::Workspace::GetFakeDataModel();
	RBX::Globals::Instance.Datamodel = RBX::Workspace::GetDataModel();
	RBX::Globals::Instance.WorkspaceToWorld = RBX::Workspace::GetWorkspaceToWorld();
	RBX::Globals::Instance.Workspace = RBX::Workspace::GetWorkspace();
	RBX::Globals::Instance.DatamodelCount = RBX::Workspace::GetDataModelPrimitiveCount();
	RBX::Globals::Instance.ClockTime = RBX::Workspace::GetClockTime();
	RBX::Globals::Instance.Players = RBX::Workspace::GetPlayers();
}