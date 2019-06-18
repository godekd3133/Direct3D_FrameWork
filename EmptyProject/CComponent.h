#pragma once
class CObject;
class CComponent 
{
public:
	CComponent(CObject * _pObj);
	virtual ~CComponent();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	bool isActive() { return true; }

public:
	bool isEnable;

protected:
	CObject * m_pObject;
};

