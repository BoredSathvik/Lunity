#ifndef NUVOLA_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA
#define NUVOLA_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA

#include "../../Module.h"
#include "../../../Events/Listener.h"
#include "../../../Events/EventHandler.h"
#include "../../../Bridge/NamespacedKey.h"
#include "../../../Bridge/LocalPlayer.h"

class Killaura : public Module {
public:
	Killaura();
	void OnEnable() override;
	void OnDisable() override;

	auto findTarget(Actor* sourceActor) -> Actor*;

	void onPlayerTickWorldEvent(PlayerTickEvent& event) override;
	void onActorRotateEvent(ActorRotateEvent& event) override;
};



#endif /* NUVOLA_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA */
