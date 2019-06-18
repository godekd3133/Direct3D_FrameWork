#include "DXUT.h"
#include "CRenderer.h"


CRenderer::CRenderer(CObject * _pObj)
	:CComponent(_pObj)
{
}


CRenderer::~CRenderer()
{
}

void CRenderer::Init()
{
	this->m_pTexture = nullptr;
	this->m_fWidth = 0.f;
	this->m_fHeight = 0.f;
	this->m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->m_rRect = Rect( 0,0,0,0);
}

void CRenderer::Update()
{

}

void CRenderer::Render()
{
	if (NULL == m_pTexture)
	{
		return;
	}

	m_pTexture->Render(
		this->m_pObject->Translation->m_vPosition,
		this->m_pObject->Translation->m_vScale,
		this->m_pObject->Translation->m_fRotation,
		this->m_rRect,
		this->m_Color);
}

void CRenderer::Release()
{
}

void CRenderer::SetTexture(CTexture * _pTexture)
{
	if (_pTexture == nullptr)
	{
		DEBUG_LOG("SetTextureFunc Error");
		return;
	}
	this->m_pTexture = _pTexture;
	this->m_fWidth = (FLOAT)_pTexture->m_Info.Width;
	this->m_fHeight = (FLOAT)_pTexture->m_Info.Height;
	m_rRect = Rect(0.f,0.f,m_fWidth, m_fHeight);

}
