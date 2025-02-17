#include "Module.h"

Module::Module(std::string name)  : Module(name, 0) {};
Module::Module(std::string name, int key) : Manager<ISetting>(name) {
	this->wasEnabled = false;
	this->SetEnabled(false);
	this->SetHotkey(key);
}

void Module::OnEnable() {

}

void Module::OnDisable() {

}

void Module::OnTick() {

}

void Module::onHotkeyCheckEvent(KeyEvent& event) {
	if(event.GetAction() == KeyAction::PRESSED) {
		if(this->GetHotkey() == event.GetKey()) {
			this->Toggle();
		}
	}
}

void Module::OnNuvolaTick() {
	if(enabled) {
		if(!wasEnabled) {
			this->OnEnable();
		}
		this->OnTick();
	} 
	if(!enabled) {
		if(wasEnabled) {
			this->OnDisable();
		}
	}
	wasEnabled = enabled;
}

auto Module::IsEnabled() -> bool {
	return this->enabled;
}

void Module::SetEnabled(bool enabled) {
	this->enabled = enabled;
}

void Module::Toggle() {
	this->SetEnabled(!this->enabled);
}

auto Module::GetHotkey() -> int {
	return this->hotkey;
};
void Module::SetHotkey(int key) {
	this->hotkey = key;
};