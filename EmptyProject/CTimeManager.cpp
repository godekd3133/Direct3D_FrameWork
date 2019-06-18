#include "DXUT.h"
#include "CTimeManager.h"


CTimeManager::CTimeManager()
{
	//mutable
}

CTimeManager::~CTimeManager()
{
	for (auto& iter : m_Timers)
	{
		SAFE_DELETE(iter.second);
	}
	m_Timers.clear();
}

CTimer * CTimeManager::AddTimer(CONSTREF(string) _Key, CTimer * _pTimer)
{
	auto find = m_Timers.find(_Key);

	if (find == m_Timers.end())
	{
		m_Timers[_Key] = _pTimer;
		return _pTimer;
	}
	
	SAFE_DELETE(_pTimer);
	return m_Timers[_Key];
}

CTimer * CTimeManager::FindTimer(CONSTREF(string) _Key)
{
	auto find = m_Timers.find(_Key);

	if (find == m_Timers.end())
		return nullptr;

	return find->second;
}

void CTimeManager::RemoveTimer(CONSTREF(string) _Key)
{
	auto find = m_Timers.find(_Key);

	if (find != m_Timers.end())
	{
		SAFE_DELETE(find->second);
		m_Timers.erase(find);
	}
}

void CTimeManager::Update()
{
	DeltaTime = DXUTGetElapsedTime();
	for (auto iter = m_Timers.begin(); iter != m_Timers.end(); )
	{
		LP(iter).second->Update();
		if (TRUE == LP(iter).second->isDestroyed())
		{
			SAFE_DELETE(LP(iter).second);
			iter = m_Timers.erase(iter);
		}
		else iter++;
	}
}
