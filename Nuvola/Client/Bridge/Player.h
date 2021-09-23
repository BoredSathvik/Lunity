#ifndef GUARD_Player
#define GUARD_Player
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
#include "Mob.h"
struct Player : public Mob {
	/* Fields */
	char padding_4880[3020];
	class GameMode* gameMode;
	/* Virtuals */
	/* Functions */
};
#endif