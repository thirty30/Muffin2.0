#pragma once
#include "Engine/Muffin.h"

class Test : public MuffinComponent
{
public:
	static CRTTIObject _RTTI_Test;
	static MuffinObject* _RTTI_CreateSelf();
};

