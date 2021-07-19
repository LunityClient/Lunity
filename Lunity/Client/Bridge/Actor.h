#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR
#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : Actor("Actor") {};
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        this->AddField("OnGround", 0x1E0);
    };

	auto IsOnGround() -> bool {
		bool* theVal = (bool*)this->GetField("OnGround");
		return *theVal;
	}
	void SetOnGround(bool onGround) {
		bool* theVal = (bool*)this->GetField("OnGround");
		*theVal = onGround;
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_ACTOR */
