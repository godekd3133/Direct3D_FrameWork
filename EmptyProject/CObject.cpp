#include "DXUT.h"
#include "CObject.h"


CObject::CObject()
{
}


CObject::~CObject()
{
	for (auto iter : m_Components)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_Components.clear();
}


void CObject::Init(ObjectTag _Tag)
{
	Translation = this->AddComponent<CTransform>();
	Translation->Init();
	m_Tag = _Tag;
	m_iDepth = 0;
}

void CObject::Render()
{
}

void CObject::Update()
{

}


void CObject::Release()
{
}


