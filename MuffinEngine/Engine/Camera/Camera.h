#pragma once
#include "../RTTI/RTTI.h"
#include "../Basic/MuffinComponent.h"

class Camera : public MuffinComponent
{
public:
	static CRTTIObject _RTTI_Camera;
	static MuffinObject* _RTTI_CreateSelf();
};

