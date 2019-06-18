#pragma once
#include "singleton.h"



class CObjectManager :
	public singleton<CObjectManager>
{
public:
	CObjectManager();
	~CObjectManager();
private:
	list<CObject *> m_Objects;
public:

	 template <typename T>
	 T * AddObject(ObjectTag _ObjectTag = Untagged)
	 {
		 if (FALSE == std::is_base_of<CObject, T>::value)
		 {
			 DEBUG_LOG("AddObject Func : Object is Not Base of CObject.");
			 return NULL;
		 }
		 CObject * pObject = new T();

		 pObject->CObject::Init(_ObjectTag);
	
		 m_Objects.push_back(pObject);
		 return dynamic_cast<T*>(pObject);
	 }

public:
	void Update();
	void Render();
};

#define OBJECT (*CObjectManager::GetInstance())