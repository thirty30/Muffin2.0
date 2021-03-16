#pragma once

#include "Core/DataStructure/TLinkedList/TLinkedList.h"
#include "Core/CommonFunction/TSingleton.h"
#include <vector>
#include <map>
using namespace std;

class CGameObject;
class CGameObjectManager
{
	T_DECLARE_SINGLETON(CGameObjectManager)

public:
	TLinkedList<CGameObject*> m_listGameObject;
	map<u64, TLinkedNode<CGameObject*>*> m_mapID2Node;
	vector<TLinkedNode<CGameObject*>*> m_vecToDel;

public:

	CGameObject* AddObject();
	CGameObject* FindObject(u64 a_nGUID);
	void RemoveObject(CGameObject* a_pGameObject);
	void Init();
	void Update(float a_fDeltaTime);
	void Clear();
};
