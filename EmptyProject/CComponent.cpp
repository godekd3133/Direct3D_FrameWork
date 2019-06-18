#include "DXUT.h"
#include "CComponent.h"
#include "CObject.h"




CComponent::CComponent(CObject * _pObj)
	:m_pObject(_pObj)
{
}

CComponent::~CComponent()
{
}

void CComponent::Init()
{
	isEnable = true;;
}

void CComponent::Update()
{
}

void CComponent::Render()
{
}

void CComponent::Release()
{
}
