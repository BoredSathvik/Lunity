#ifndef GUARD_Actor
#define GUARD_Actor
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
#include "AABB.h"
#include "ActorType.h"
struct Actor {
	/* Fields */
	char padding_320[312];
	Vector2<float> lookingVec;
	char padding_480[152];
	bool onGround;
	char padding_864[383];
	class BlockSource* blockSource;
	class Dimension* dimension;
	class Level* level;
	char padding_1000[112];
	ActorType entityTypeId;
	char padding_1232[160];
	AABB hitbox;
	Vector2<float> size;
	Vector3<float> position;
	Vector3<float> oldPos;
	Vector3<float> velocity;
	char padding_1368[64];
	size_t actorRuntimeID;
	/* Virtuals */
	virtual void virt_pad_0() {};
	virtual void virt_pad_1() {};
	virtual void virt_pad_2() {};
	virtual void virt_pad_3() {};
	virtual void virt_pad_4() {};
	virtual void virt_pad_5() {};
	virtual void virt_pad_6() {};
	virtual void virt_pad_7() {};
	virtual void virt_pad_8() {};
	virtual void virt_pad_9() {};
	virtual void virt_pad_10() {};
	virtual void virt_pad_11() {};
	virtual void virt_pad_12() {};
	virtual void virt_pad_13() {};
	virtual void virt_pad_14() {};
	virtual auto getPos() -> Vector3<float>* {};
	virtual void virt_pad_16() {};
	virtual void virt_pad_17() {};
	virtual void virt_pad_18() {};
	virtual void virt_pad_19() {};
	virtual void virt_pad_20() {};
	virtual void virt_pad_21() {};
	virtual void virt_pad_22() {};
	virtual void virt_pad_23() {};
	virtual void virt_pad_24() {};
	virtual void virt_pad_25() {};
	virtual void virt_pad_26() {};
	virtual void virt_pad_27() {};
	virtual void virt_pad_28() {};
	virtual void virt_pad_29() {};
	virtual void virt_pad_30() {};
	virtual void virt_pad_31() {};
	virtual void virt_pad_32() {};
	virtual void virt_pad_33() {};
	virtual void virt_pad_34() {};
	virtual void virt_pad_35() {};
	virtual void virt_pad_36() {};
	virtual void virt_pad_37() {};
	virtual void virt_pad_38() {};
	virtual void virt_pad_39() {};
	virtual void virt_pad_40() {};
	virtual void virt_pad_41() {};
	virtual void virt_pad_42() {};
	virtual void virt_pad_43() {};
	virtual void virt_pad_44() {};
	virtual void virt_pad_45() {};
	virtual void virt_pad_46() {};
	virtual void virt_pad_47() {};
	virtual void virt_pad_48() {};
	virtual void virt_pad_49() {};
	virtual void virt_pad_50() {};
	virtual void virt_pad_51() {};
	virtual void virt_pad_52() {};
	virtual void virt_pad_53() {};
	virtual void virt_pad_54() {};
	virtual void virt_pad_55() {};
	virtual void virt_pad_56() {};
	virtual void virt_pad_57() {};
	virtual void virt_pad_58() {};
	virtual void virt_pad_59() {};
	virtual void virt_pad_60() {};
	virtual void virt_pad_61() {};
	virtual void virt_pad_62() {};
	virtual void virt_pad_63() {};
	virtual void virt_pad_64() {};
	virtual void virt_pad_65() {};
	virtual void virt_pad_66() {};
	virtual void virt_pad_67() {};
	virtual void virt_pad_68() {};
	virtual void virt_pad_69() {};
	virtual void virt_pad_70() {};
	virtual void virt_pad_71() {};
	virtual void virt_pad_72() {};
	virtual void virt_pad_73() {};
	virtual void virt_pad_74() {};
	virtual void virt_pad_75() {};
	virtual void virt_pad_76() {};
	virtual void virt_pad_77() {};
	virtual void virt_pad_78() {};
	virtual void virt_pad_79() {};
	virtual void virt_pad_80() {};
	virtual void virt_pad_81() {};
	virtual void virt_pad_82() {};
	virtual void virt_pad_83() {};
	virtual void virt_pad_84() {};
	virtual void virt_pad_85() {};
	virtual void virt_pad_86() {};
	virtual void virt_pad_87() {};
	virtual void virt_pad_88() {};
	virtual void virt_pad_89() {};
	virtual void virt_pad_90() {};
	virtual void virt_pad_91() {};
	virtual void virt_pad_92() {};
	virtual void virt_pad_93() {};
	virtual void virt_pad_94() {};
	virtual void virt_pad_95() {};
	virtual void virt_pad_96() {};
	virtual auto isAlive() -> bool {};
	/* Functions */
};
#endif