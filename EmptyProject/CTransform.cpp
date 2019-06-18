#include "DXUT.h"
#include "CTransform.h"


CTransform::CTransform(CObject * _pObj)
	: CComponent(_pObj)
{

}


CTransform::~CTransform()
{
}


void CTransform::Init()
{
	this->m_vPosition = Vector2(0.f, 0.f);
	this->m_vScale = Vector2(1.f, 1.f);
	this->m_fRotation = 0.f;
}

void CTransform::Update()
{
}

void CTransform::Render()
{
}

void CTransform::Release()
{
}
