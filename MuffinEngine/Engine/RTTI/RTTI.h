#pragma once
#include <map>
#include <functional>
using namespace std;

class MuffinObject;
class CRTTIObject
{
private:
	static map<u64, CRTTIObject*>* m_mapRttiObjects;
	function<MuffinObject* ()> m_funcRttiCtor;

public:
	CRTTIObject(u64 a_nID, function<MuffinObject* ()> a_funcRttiCtor);

	void RegisterMuffinObject(u64 a_nID);

	static CRTTIObject* FindRTTIObject(u64 a_nID);

	static MuffinObject* ConstructObject(u64 a_nID);
};

#define DECLARE_CLASS_RTTI(NAME) \
	public: \
		static CRTTIObject _RTTI_##NAME; \
		static MuffinObject* _RTTI_CreateSelf();

#define IMPLEMENT_CLASS_RTTI(NAME) \
	CRTTIObject NAME::_RTTI_##NAME(typeid(NAME).hash_code(), NAME::_RTTI_CreateSelf); \
	MuffinObject* NAME::_RTTI_CreateSelf() { return new NAME(); }
