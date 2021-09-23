#ifndef GUARD_Level
#define GUARD_Level
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct Level {
	/* Fields */
	char padding_112[112];
	std::vector<Player*> players;
	char padding_2608[2472];
	class Actor* targetEntity;
	std::vector<Actor*> actors;
	/* Virtuals */
	/* Functions */
};
#endif