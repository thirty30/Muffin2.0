#pragma once
#include "../Basic/MuffinObject.h"

class MuffinComponent : public MuffinObject
{
private:
	tbool m_bIsInitialized;
	tbool m_bIsStarted;
	tbool m_bIsEnable;
	friend class CGameObject;

public:
	CGameObject* pGameObject;

public:
	virtual ~MuffinComponent() {};

	virtual void OnInitialize() {}
	virtual void OnStart() {}
	virtual void OnUpdate() {}
	virtual void OnDestroy() {}


};
