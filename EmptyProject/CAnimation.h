#pragma once
#include "CComponent.h"
#include "CAnimator.h"
class CTimer;
class CAnimation : public CComponent
{
public:
	CAnimation(CObject * pObject);
	~CAnimation();

private:
	map<string,CAnimator *> m_Animators;
	CAnimator * m_pHandleAnimator = nullptr;

public:
	void SetHandleAnimator(const string& _Key);
	void AddAnimator(const string& _Key, const string& _resKey, float _fDelay, bool _bLoop);
	CAnimator * GetHandleAnimator() { return m_pHandleAnimator; }

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:

};

