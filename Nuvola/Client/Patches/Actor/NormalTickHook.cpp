#include  "NormalTickHook.h"

#include "../../Events/EventHandler.h"

void __fastcall NormalTickHook::NormalTickHookCallback_1_17_11_1(Actor* actor) {
	
	//TODO: form entity list
	/*
	std::vector<Actor*>* actors = Utils::GetActorList();
	actors->push_back(actor);
	*/

	NormalTickEvent event(actor);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onNormalTickEvent(event);
	}
	PLH::FnCast(funcOriginal, &NormalTickHookCallback_1_17_11_1)(actor);
}

NormalTickHook::NormalTickHook() : IPatch::IPatch("Actor::NormalTick") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? 55 48 ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? 8B ?? ?? ?? ?? ?? 48 8B ?? ?? 81"), -1));
}

auto NormalTickHook::Apply() -> bool {
	return this->AutoPatch(&NormalTickHookCallback_1_17_11_1, &funcOriginal);
}