#ifndef NUVOLA_CLIENT_FEATURES_MODULE
#define NUVOLA_CLIENT_FEATURES_MODULE
#include <iostream>
#include <string>
#include <utility>
#include "Manager.h"
#include "Setting.h"
#include "../Events/Listener.h"

class Module : public Manager<ISetting>, public Listener {
	bool enabled;
	bool wasEnabled;
	int hotkey;
public:
    Module(std::string name);
    Module(std::string name, int hotkey);

    virtual void OnEnable();
    virtual void OnDisable();
	virtual void OnTick();
	virtual void onHotkeyCheckEvent(KeyEvent& event);
	void OnNuvolaTick();
	auto IsEnabled() -> bool;
	void SetEnabled(bool enabled);
	void Toggle();
	auto GetHotkey() -> int;
	void SetHotkey(int key);
};


#endif /* NUVOLA_CLIENT_FEATURES_MODULE */
