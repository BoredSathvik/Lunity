#include "SetupAndRenderHook.h"

#include <string>

#include "../../../Render/IAnimWrapper.h"
#include "../../../Render/RenderContext/MinecraftRenderer.h"
#include "../../../Render/Custom/Renderer.h"
#include "../../Events/EventHandler.h"
#include "../../Events/RenderEvent.h"

bool other = false;
void __fastcall SetupAndRenderHook::setupAndRenderCallback_1_17_10_4(class ScreenView* screenView, class MinecraftUIRenderContext* renderContext) {
	PLH::FnCast(setupAndRenderOriginal, setupAndRenderCallback_1_17_10_4)(screenView, renderContext);

	IAnimWrapper::NewFrame();

	Renderer::Setup(renderContext);
	MinecraftRenderer renderer = MinecraftRenderer(renderContext);
	RenderEvent event(renderContext, &renderer);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onRenderEvent(event);
	}
}

SetupAndRenderHook::SetupAndRenderHook() : IPatch::IPatch("ScreenView::setupAndRender") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
}

auto SetupAndRenderHook::Apply() -> bool {
	return this->AutoPatch(setupAndRenderCallback_1_17_10_4, &setupAndRenderOriginal);
}