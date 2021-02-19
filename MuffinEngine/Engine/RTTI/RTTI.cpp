#include "pch.h"
#include "RTTI.h"
#include "../Basic/MuffinObject.h"

map<u64, CRTTIObject*>* CRTTIObject::m_mapRttiObjects;

CRTTIObject::CRTTIObject(u64 a_nID, function<MuffinObject* ()> a_funcRttiCtor)
{
	this->m_funcRttiCtor = a_funcRttiCtor;
	this->RegisterMuffinObject(a_nID);
}

void CRTTIObject::RegisterMuffinObject(u64 a_nID)
{
	if (m_mapRttiObjects == nullptr)
	{
		m_mapRttiObjects = new map<u64, CRTTIObject*>();
	}
	pair<u64, CRTTIObject*> p(a_nID, this);
	m_mapRttiObjects->insert(p);
}

CRTTIObject* CRTTIObject::FindRTTIObject(u64 a_nID)
{
	if (m_mapRttiObjects == nullptr)
	{
		return nullptr;
	}

	map<u64, CRTTIObject*>::iterator it = m_mapRttiObjects->find(a_nID);
	if (it == m_mapRttiObjects->end())
	{
		return nullptr;
	}

	return (*it).second;
}

MuffinObject* CRTTIObject::ConstructObject(u64 a_nID)
{
	CRTTIObject* pObj = FindRTTIObject(a_nID);
	return (pObj != nullptr) ? pObj->m_funcRttiCtor() : nullptr;
}
