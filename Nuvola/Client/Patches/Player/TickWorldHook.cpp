#include  "TickWorldHook.h"

#include "../../Events/Listener.h"
#include "../../Events/EventHandler.h"

void* __fastcall TickWorldHook::TickWorldHookCallback_1_17_11_1(Player* player, class Tick* tick) {
	void* ret = PLH::FnCast(funcOriginal, &TickWorldHookCallback_1_17_11_1)(player, tick);
	LocalPlayer* localPlayer = Utils::GetClientInstance()->clientPlayer;
static_assert(offsetof(Player, gameMode)==0x12E8, "Player::gameMode is misaligned!");
	PlayerTickEvent event(player->gameMode, player, localPlayer==player);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onPlayerTickWorldEvent(event);
	}
	return ret;
}

TickWorldHook::TickWorldHook() : IPatch::IPatch("Player::TickWorld") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? ?? 89 ?? ?? ?? 57 41 ?? 41 ?? 48 83 ?? ?? 48 8B ?? 45 33 ?? ?? 89 ?? ?? ?? ?? B9"), -1)); //1.17.30.4
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? 89 ?? ?? 48 8B ?? 41"), -1)); //1.17.11.1
}

auto TickWorldHook::Apply() -> bool {
	return this->AutoPatch(&TickWorldHookCallback_1_17_11_1, &funcOriginal);
}