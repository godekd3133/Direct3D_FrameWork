#pragma once
#include "singleton.h"
class CInputManager :
	public singleton<CInputManager>
{
public:
	CInputManager();
	~CInputManager();
private:
	bool m_bCurInput[256];
	bool m_bLastInput[256];
public:
	void Update();

	bool KeyDown(int Key);
	bool KeyUp(int Key);
	bool KeyPress(int Key);

	Vector2 GetMousePos();
	POINT ptGetMousePos();


};

#define INPUT (*CInputManager::GetInstance())
