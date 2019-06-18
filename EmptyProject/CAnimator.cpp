#include "DXUT.h"
#include "CAnimator.h"


CAnimator::CAnimator()
{
}


CAnimator::~CAnimator()
{
}


void CAnimator::Init(const string & _Key, float _fDelay, bool _bLoop)
{
	m_fDelay = _fDelay;
	m_bLoop = _bLoop;
	m_bActive = true;
	m_Textures = IMAGE.MakeVecTex(_Key);
	m_iFrame = 0;
	m_iMaxFrame = m_Textures.size() - 1;
	m_pTimer = new CTimer(_fDelay, [&]()->void
		{
			m_iFrame++;
			if (m_iFrame > m_iMaxFrame)
			{
				m_iFrame = 0;
				if (!m_bLoop) m_bActive = false;
			}
		});

}

void CAnimator::Update()
{
	m_pTimer->Update();
}

void CAnimator::Render()
{
}

void CAnimator::Release()
{
	SAFE_DELETE(m_pTimer);
}
