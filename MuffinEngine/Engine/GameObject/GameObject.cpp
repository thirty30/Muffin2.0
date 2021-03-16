#include "pch.h"
#include "GameObject.h"
#include "GameObjectManager.h"

void CGameObject::PreUpdate()
{
	TLinkedNode<MuffinComponent*>* pNode = this->m_pComponents.GetHeadNode();
	while (pNode != NULL)
	{
		MuffinComponent* pCom = pNode->m_pValue;
		if (pCom->m_bIsEnable == true && pCom->m_bIsStarted == false)
		{
			pCom->m_bIsStarted = true;
			pCom->OnStart();
		}
		pNode = pNode->m_pNext;
	}
}

void CGameObject::Update(float a_fDeltaTime)
{
	TLinkedNode<MuffinComponent*>* pNode = this->m_pComponents.GetHeadNode();
	while (pNode != NULL)
	{
		bool bIsEnable = pNode->m_pValue->m_bIsEnable;
		if (bIsEnable == true)
		{
			pNode->m_pValue->OnUpdate();
		}
		pNode = pNode->m_pNext;
	}
}

void CGameObject::Clear()
{
	while (this->m_pComponents.GetLength() > 0)
	{
		TLinkedNode<MuffinComponent*>* pNode = this->m_pComponents.PopBack();
		pNode->m_pValue->OnDestroy();
		delete pNode->m_pValue;
		delete pNode;
	}
}

CGameObject* CGameObject::Initialize()
{
	return CGameObjectManager::GetSingleton().AddObject();
}

void CGameObject::Destroy(CGameObject* a_pGameObject)
{
	CGameObjectManager::GetSingleton().RemoveObject(a_pGameObject);
}




