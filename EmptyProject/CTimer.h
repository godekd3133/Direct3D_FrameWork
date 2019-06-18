#pragma once
class CTimer
{
public:
	CTimer(FLOAT _fCycle,function<void()> _Func, BOOL _bOnce = false);
	~CTimer();
private:
	BOOL m_bEnable = true;
	BOOL m_bDestroyed = false;
	BOOL m_bOnce;
	TimePoint m_OldTimePoint;
	function<void()> m_Func;

	Second m_Duraction;
	FLOAT m_fCycle;
public:
	void Update();
	BOOL isDestroyed() { return m_bDestroyed; }
	FLOAT GetDuraction() { return (FLOAT)m_Duraction.count(); }
	void SetFunc(function<void()> _Func) { m_Func = _Func; }
	//bool 
};

