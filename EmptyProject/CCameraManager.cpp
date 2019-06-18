#include "DXUT.h"
#include "CCameraManager.h"


CCameraManager::CCameraManager()
{
	m_vPos = SCREEN_CENTER;
	m_vSize = { WINSIZEX,WINSIZEY };
	m_matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		-m_vPos.x, -m_vPos.y, 0, 1);
	D3DXMatrixOrthoLH(&m_matProj, m_vSize.x, -m_vSize.y, 0, 1);
}


CCameraManager::~CCameraManager()
{
}

void CCameraManager::Update()
{
	if (m_fTime >= m_fShakeTime)
	{
		m_fTime = 0.f;
		m_bShake = false;
	}
	else m_fTime +=	TIME.DeltaTime;

	if (m_bShake == false)
	{
		Lerp(&m_vPos.y, m_vPos.y, 360.f, TIME.DeltaTime  * 2.f);
	}
	else  m_vPos += D3DXVECTOR2(rand() % (INT)(m_iShakePower)-(INT)(m_iShakePower / 2), rand() % (INT)(m_iShakePower)-(INT)(m_iShakePower / 2));
	m_matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		-m_vPos.x, -m_vPos.y, 0, 1);
}

void CCameraManager::SetTransform()
{
	g_Device->SetTransform(D3DTS_PROJECTION, &m_matProj);
	g_Device->SetTransform(D3DTS_VIEW, &m_matView);
}
void CCameraManager::CameraShake(float fTime, int iPower)
{
	m_fTime = 0.f;
	m_fShakeTime = fTime;
	m_iShakePower = iPower;
	m_bShake = true;
}