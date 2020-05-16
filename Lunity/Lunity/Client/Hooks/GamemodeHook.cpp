#include "pch.h"
#include "GamemodeHook.h"
#include <MinHook.h>
#include "../CheatManager.h"

typedef int (WINAPI* GamemodeTick)(GameMode* gm);
GamemodeTick gmOriginal;
GamemodeTick smOriginal;

static GameMode* thisGm = nullptr;
int gmHookCallback(GameMode* gm) {
	thisGm = gm;
	int retval = gmOriginal(gm);
	CheatManager::gmTickCheats(gm);
	return retval;
}

int smHookCallback(GameMode* gm) {
	thisGm = gm;
	int retval = smOriginal(gm);
	CheatManager::gmTickCheats(gm);
	return retval;
}

GameMode* GamemodeHook::getLastGm()
{
	return thisGm;
}

void GamemodeHook::installHook()
{
	log("installing gamemode hook...");
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	logHex("ToHook", (ulong)toGmHook);
	bool installSuccess = false;
	if (MH_CreateHook(toGmHook, &gmHookCallback, reinterpret_cast<LPVOID*>(&gmOriginal)) == MH_OK) {
		log("Gamemode Hook successfully created!");
		if (MH_EnableHook(toGmHook) == MH_OK) {
			installSuccess = true;
			log("gamemode hook installed");
		}
	}
	if (!installSuccess) {
		log("Failed to hook gamemode!");
	}

	log("installing survivalmode hook...");
	void* toSmHook = (void*)(LunMem::getBaseModule() + 0x14FEF90);
	logHex("ToHook", (ulong)toSmHook);
	bool smInstallSuccess = false;
	if (MH_CreateHook(toSmHook, &smHookCallback, reinterpret_cast<LPVOID*>(&smOriginal)) == MH_OK) {
		log("survivalmode Hook successfully created!");
		if (MH_EnableHook(toSmHook) == MH_OK) {
			smInstallSuccess = true;
			log("survivalmode hook installed");
		}
	}
	if (!smInstallSuccess) {
		log("Failed to hook survivalmode!");
	}
}

void GamemodeHook::uninstallHook()
{
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	MH_DisableHook(toGmHook);
	void* toSmHook = (void*)(LunMem::getBaseModule() + 0x14FEF90);
	MH_DisableHook(toSmHook);
}
