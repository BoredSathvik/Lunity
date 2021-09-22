#include "SendChatMessageHook.h"

#include "../../Features/CommandMgr.h"
#include "../../Events/EventHandler.h"

void __fastcall SendChatMessageHook::clientInstanceCallback_1_17_11_1(class ClientInstanceScreenModel* screenModel, nuv::string* text) {

	ChatEvent event(text->getString());
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onChatEvent(event);
	}
	if(event.IsCancelled()) {
		return;
	}
	
    PLH::FnCast(funcOriginal, &clientInstanceCallback_1_17_11_1)(screenModel, text);
}

SendChatMessageHook::SendChatMessageHook() : IPatch::IPatch("ClientInstanceScreenModel::SendChatMessage") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? 4C 8B ?? 48 ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? ?? ?? 48"), -1));
}

auto SendChatMessageHook::Apply() -> bool {
	return this->AutoPatch(clientInstanceCallback_1_17_11_1, &funcOriginal);
}