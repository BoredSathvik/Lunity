#pragma once
#include "../Cheat.h"
class ClickGUI : public Cheat
{
public:
	ClickGUI();
	void onMouseMove();
	void onPostRender();
};

