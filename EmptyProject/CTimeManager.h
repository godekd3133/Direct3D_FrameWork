#pragma once
#include "singleton.h"
#include "CTimer.h"

class CTimeManager :
	public singleton<CTimeManager>
{
public:
	CTimeManager();
	~CTimeManager();
public:
	FLOAT DeltaTime;
private:
	map<string, CTimer *> m_Timers;
public:
	CTimer * AddTimer(CONSTREF(string) _Key, CTimer * _pTimer);
	CTimer * FindTimer(CONSTREF(string) _Key);
	void RemoveTimer(CONSTREF(string) _Key);


	void Update();
};

#define TIME (*CTimeManager::GetInstance())
#define GetNowTimepoint chrono::system_clock::now()
