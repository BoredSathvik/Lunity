#ifndef NUVOLA_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK
#define NUVOLA_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"

#include "../../Bridge/LocalPlayer.h"

class SetYHeadRotHook : public IPatch {
	static void __fastcall SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, Actor* camera);
public:
	static inline uintptr_t funcOriginal = 0;
	SetYHeadRotHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK */
