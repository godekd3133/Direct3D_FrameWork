#pragma once
#include "CScene.h"
class CPlayer;
class CMainScene :
	public CScene
{
public:
	CMainScene();
	~CMainScene();
	CPlayer * m_pPlayer01;
	CPlayer * m_pPlayer02;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

