#include "DXUT.h"
#include "CTimer.h"



CTimer::CTimer(FLOAT _fCycle, function<void()> _Func, BOOL _bOnce)
	: m_fCycle(_fCycle),m_Func(_Func), m_bOnce(_bOnce)
{
	m_OldTimePoint = GetNowTimepoint;
}

CTimer::~CTimer()
{
}

void CTimer::Update()
{
	m_Duraction = GetNowTimepoint - m_OldTimePoint;

	if ((FLOAT)m_Duraction.count() >= m_fCycle)
	{
		m_OldTimePoint = GetNowTimepoint;
		
		if (TRUE == m_bEnable)
			m_Func();

		if (TRUE == m_bOnce)
		{
			m_bDestroyed = TRUE;
			m_bEnable = FALSE;
		}
	}
}

