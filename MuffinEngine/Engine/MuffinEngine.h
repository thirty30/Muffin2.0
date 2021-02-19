#pragma once
#include "./RTTI/RTTI.h"

//void RegisterRTTI();

template<typename T>
T* AddComponent()
{
	MuffinObject* pObj = CRTTIObject::ConstructObject(typeid(T).hash_code());
	return static_cast<T*>(pObj);
}
