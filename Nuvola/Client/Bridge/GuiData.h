#ifndef GUARD_GuiData
#define GUARD_GuiData
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct GuiData {
	/* Fields */
	char padding_24[24];
	Vector2<float> resolution;
	char padding_40[8];
	Vector2<float> scaledResolution;
	char padding_56[8];
	float scale;
	char padding_82[22];
	Vector2<short> mousePos;
	/* Virtuals */
	/* Functions */
	static inline uintptr_t holder_displayClientMessage;
	auto __thiscall displayClientMessage(nuv::string message) -> void {
		if(holder_displayClientMessage == 0) {
			holder_displayClientMessage = Mem::FindSig("48 89 5c 24 18 48 89 74 24 20 55 57 41 54 41 56 41 57 48 8d 6c 24 c0 48 81 ec 40 01 00 00 48 8b 05 ?? ?? ?? ?? 48 33 C4 48 89 45 30 4C 8B F1");
		}
		if(holder_displayClientMessage == 0){
			Utils::DebugF("FATAL: Sig failure for displayClientMessage");
		}
		holder_displayClientMessage += -0;
		return ((void(__thiscall*)(GuiData*, nuv::string message))holder_displayClientMessage)(this, message);
	};
};
#endif