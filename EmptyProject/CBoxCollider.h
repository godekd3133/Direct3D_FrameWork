#pragma once
#include "CComponent.h"
enum CollisionStatus
{
	COLS_NONE = 0,
	COLS_OnEnter,
	COLS_OnStay,
	COLS_OnExit
};
class CBoxCollider :
	public CComponent
{
public:
	CBoxCollider(CObject * _pObject);
	~CBoxCollider();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

	void SetCollisionBox(const Rect& _CollisionBox);


	bool m_bIsTrigger;
public:
	//충돌처리에 사용되는 좌표가 절대적인 사각형
	Rect m_reBox;


	Rect m_reRect;

	CollisionStatus m_Status;

private:
};

