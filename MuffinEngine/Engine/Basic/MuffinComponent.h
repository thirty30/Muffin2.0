#pragma once
#include "../Basic/MuffinObject.h"

class MuffinComponent : public MuffinObject
{
private:
	tbool m_bIsInitialized;

public:
	virtual ~MuffinComponent() {};

	virtual void Initialize() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void OnDestroy() {}
};
