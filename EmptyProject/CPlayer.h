#pragma once
#include "CObject.h"

enum class PLAYER_STATUS
{
	Run = 0,
	Jump,
	DoubleJump,
	Slide,
};
class CPlayer :
	public CObject
{

public:
	CPlayer();
	~CPlayer();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	virtual void OnCollisionEnter(CObject * _pObject)override;
	virtual void OnCollisionStay(CObject * _pObject) override;
	virtual void OnCollisionExit(CObject * _pObject) override;
	virtual void OnTriggerEnter(CObject * _pObject)	 override;
	virtual void OnTriggerStay(CObject * _pObject)	 override;
	virtual void OnTriggerExit(CObject * _pObject)	 override;
private:
//   	map<PLAYER_STATUS,CAnimation *> m_Animations; 
	PLAYER_STATUS m_Status;
};

