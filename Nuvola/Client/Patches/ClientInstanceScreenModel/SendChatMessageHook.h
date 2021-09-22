#ifndef NUVOLA_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGEHOOK
#define NUVOLA_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGEHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

class SendChatMessageHook : public IPatch {
	static void clientInstanceCallback_1_17_11_1(class ClientInstanceScreenModel* screenModel, nuv::string* text);
public:
	static inline uintptr_t funcOriginal = 0;
	SendChatMessageHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGEHOOK */
