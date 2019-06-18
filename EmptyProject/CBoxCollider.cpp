#include "DXUT.h"
#include "CBoxCollider.h"


CBoxCollider::CBoxCollider(CObject * _pObject)
	: CComponent(_pObject)
{
}


CBoxCollider::~CBoxCollider()
{
}

void CBoxCollider::Init()
{
	m_reBox = Rect(0.f, 0.f, 0.f, 0.f);
	m_reRect = Rect(0.f, 0.f, 0.f, 0.f);
	m_Status = COLS_NONE;
	m_bIsTrigger = true;
}

void CBoxCollider::Update()
{
	auto Renderer = m_pObject->GetComponent<CRenderer>();

	m_reRect = Rect(
		this->m_pObject->Translation->m_vPosition.x - (Renderer->m_fWidth / 2.f) + m_reBox.Left,
		this->m_pObject->Translation->m_vPosition.y - (Renderer->m_fHeight / 2.f) + m_reBox.Top,
		this->m_pObject->Translation->m_vPosition.x - (Renderer->m_fWidth / 2.f) + m_reBox.Right,
		this->m_pObject->Translation->m_vPosition.y - (Renderer->m_fHeight / 2.f) + m_reBox.Bottom);

}

void CBoxCollider::Render()
{
	Rect re = m_reBox;
	re.Rotate(m_pObject->Translation->m_fRotation);
	

	//IMAGE.RenderLine(re.GetLT(), re.GetRT(), 2, D3DCOLOR_ARGB(255, 255, 255, 2));
	//IMAGE.RenderLine(re.GetLT(), re.GetLB(), 2, D3DCOLOR_ARGB(255, 255, 255, 2));
	//IMAGE.RenderLine(re.GetLB(), re.GetRB(), 2, D3DCOLOR_ARGB(255, 255, 255, 2));
	//IMAGE.RenderLine(re.GetRT(), re.GetRB(), 2, D3DCOLOR_ARGB(255, 255, 255, 2));

	IMAGE.RenderLine(re.GetLT(), Vector2(re.GetLT().x, re.GetLT().y +1.f), 20, D3DCOLOR_ARGB(255, 255, 255, 2));
	IMAGE.RenderLine(re.GetRT(), Vector2(re.GetRT().x, re.GetRT().y +1.f), 29, D3DCOLOR_ARGB(255, 255, 255, 2));
	IMAGE.RenderLine(re.GetLB(),Vector2(re.GetLB().x, re.GetLB().y +1.f), 20, D3DCOLOR_ARGB(255, 255, 255, 2));
	IMAGE.RenderLine(re.GetRB(),Vector2(re.GetRB().x, re.GetRB().y +1.f), 20, D3DCOLOR_ARGB(255, 255, 255, 2));

}

void CBoxCollider::Release()
{
}

void CBoxCollider::SetCollisionBox(const Rect & _CollisionBox)
{
	m_reBox = _CollisionBox;
}
