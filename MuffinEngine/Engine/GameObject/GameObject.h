#pragma once

#include "Core/DataStructure/TLinkedList/TLinkedList.h"
#include "../Basic/MuffinComponent.h"

class CGameObject
{
private:
	u64 m_nGUID = 0;
	bool m_bActived = true;
	TLinkedList<MuffinComponent*> m_pComponents;

	friend class CGameObjectManager;

private:
	void PreUpdate();
	void Update(float a_fDeltaTime);
	void Clear();

	CGameObject() = default;
	~CGameObject() = default;
	CGameObject(const CGameObject& other) = default;
	CGameObject& operator= (const CGameObject& other) = default;

public:
	inline void SetActived(bool a_bActived) { this->m_bActived = a_bActived; }
	inline bool IsActived() { return this->m_bActived; }
	inline u64 GetGameObjectID() { return this->m_nGUID; }

	static CGameObject* Initialize();
	static void Destroy(CGameObject* a_pGameObject);

	template<typename T>
	T* AddComponent();
	template<typename T>
	T* GetComponent();
};

template<typename T>
T* CGameObject::AddComponent()
{
	MuffinComponent* pComponent = new T();
	pComponent->pGameObject = this;
	pComponent->OnInitialize();
	TLinkedNode<MuffinComponent*>* pNode = new TLinkedNode<MuffinComponent*>(pComponent);
	this->m_pComponents.PushBack(pNode);
	return static_cast<T*>(pComponent);
}

template<typename T>
T* CGameObject::GetComponent()
{
	TLinkedNode<MuffinComponent*>* pHead = this->m_pComponents.GetHeadNode();
	while (pHead != NULL)
	{
		if (typeid(*pHead->m_pValue) == typeid(T))
		{
			return static_cast<T*>(pHead->m_pValue);
		}
		pHead = pHead->m_pNext;
	}
	return NULL;
}

