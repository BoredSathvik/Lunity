#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

//Actor
#include "Actor/SetRotHook.h"
#include "Actor/NormalTickHook.h"
//Mob
#include "Mob/SwingHook.h"
//Player
#include "Player/TickWorldHook.h"
//Localplayer
#include "LocalPlayer/SetYHeadRotHook.h"
//LoopbackPacketSender
#include "LoopbackPacketSender/SendToServerHook.h"
//ClientInstance
#include "ClientInstance/UpdateHook.h"
//ClientInstanceScreenModel
#include "ClientInstanceScreenModel/SendChatMessageHook.h"
//Global or Unknown
#include "Global/KeyPressHook.h"
#include "Global/MouseActionHook.h"
//MeshHelpers
#include "MeshHelpers/RenderMeshHook.h"
//ScreenView
#include "ScreenView/SetupAndRenderHook.h"
//SurvivalMode
// #include "SurvivalMode/TickHook.h"

void PatchManager::ApplyAll()
{
	/* Input hooking */
	PatchManager::ApplyPatch(new KeyPressHook());
	PatchManager::ApplyPatch(new MouseActionHook());

	/* ClientInstance reference receiver hook */
	PatchManager::ApplyPatch(new UpdateHook());

	/* Command shit */
	PatchManager::ApplyPatch(new SendChatMessageHook());

	/* Graphics hooking */
	PatchManager::ApplyPatch(new SetupAndRenderHook());

	/* LocalPlayer patches */
	PatchManager::ApplyPatch(new SetYHeadRotHook()); // This func has head & camera math

	/* LoopbackPacketSender patches */
	PatchManager::ApplyPatch(new SendToServerHook());

	/* Actor patches */
	PatchManager::ApplyPatch(new SetRotHook()); // This has for up & down rotation which is shared across the whole body, however only the head moves.
	//PatchManager::ApplyPatch(new NormalTickHook());

	/* Mob patches */
	PatchManager::ApplyPatch(new SwingHook());

	/* Player patches */
	PatchManager::ApplyPatch(new TickWorldHook());
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
        PatchManager::patches->push_back(toAdd);
        Utils::DebugF("Successfully applied \'" + toAdd->GetName() + "\' patch!");
    }
    else
    {
        Utils::DebugF("Failed to apply patch: " + toAdd->GetName());
    }
}

auto PatchManager::RemoveAll() -> bool {
	for(auto patch : *PatchManager::patches) {
		PatchManager::RemovePatch(patch);
	}
	return true;
}
auto PatchManager::RemovePatch(class IPatch* toRemove) -> bool {
	delete toRemove;
	return true;
}