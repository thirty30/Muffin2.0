#include "pch.h"
#include "GameObjectManager.h"
#include "GameObject.h"

T_IMPLEMENT_SINGLETON(CGameObjectManager)

void CGameObjectManager::Init()
{
	this->m_mapID2Node.clear();
	this->m_vecToDel.clear();
}

void CGameObjectManager::Clear()
{
	while (this->m_listGameObject.GetLength() > 0)
	{
		TLinkedNode<CGameObject*>* pNode = this->m_listGameObject.PopBack();
		delete pNode->m_pValue;
		delete pNode;
	}
	this->m_mapID2Node.clear();
}

CGameObject* CGameObjectManager::AddObject()
{
	CGameObject* pNewObject = new CGameObject();
	pNewObject->m_nGUID = 0;
	TLinkedNode<CGameObject*>* pNode = new TLinkedNode<CGameObject*>(pNewObject);
	this->m_listGameObject.PushBack(pNode);
	this->m_mapID2Node[pNewObject->m_nGUID] = pNode;
	return pNewObject;
}

CGameObject* CGameObjectManager::FindObject(u64 a_nGUID)
{
	map<u64, TLinkedNode<CGameObject*>*>::iterator iter = this->m_mapID2Node.find(a_nGUID);
	if (iter == this->m_mapID2Node.end())
	{
		return NULL;
	}
	return iter->second->m_pValue;
}

void CGameObjectManager::RemoveObject(CGameObject* a_pGameObject)
{
	u64 nGUID = a_pGameObject->m_nGUID;
	map<u64, TLinkedNode<CGameObject*>*>::iterator iter = this->m_mapID2Node.find(nGUID);
	if (iter == this->m_mapID2Node.end())
	{
		return;
	}
	this->m_vecToDel.push_back(iter->second);
}

void CGameObjectManager::Update(float a_fDeltaTime)
{
	//Destroy gameobject in todel list
	for (int i = 0; i < this->m_vecToDel.size(); i++)
	{
		TLinkedNode<CGameObject*>* pNode = this->m_vecToDel[i];
		this->m_listGameObject.RemoveNode(pNode);
		CGameObject* pObj = pNode->m_pValue;
		this->m_mapID2Node.erase(pObj->m_nGUID);
		pObj->Clear();
		delete pObj;
		delete pNode;
	}

	TLinkedNode<CGameObject*>* pHead = nullptr;

	pHead = this->m_listGameObject.GetHeadNode();
	while (pHead != nullptr)
	{
		if (pHead->m_pValue->IsActived() == true)
		{
			pHead->m_pValue->PreUpdate();
		}
		pHead = pHead->m_pNext;
	}

	pHead = this->m_listGameObject.GetHeadNode();
	while (pHead != nullptr)
	{
		if (pHead->m_pValue->IsActived() == true)
		{
			pHead->m_pValue->Update(a_fDeltaTime);
		}
		pHead = pHead->m_pNext;
	}
}

