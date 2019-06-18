#pragma once
#include "singleton.h"
class CCameraManager :
	public singleton<CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();
public:
	void Update();
	void SetTransform();
	void SetFollow(Vector2 * vFollow)
	{
		if (vFollow == nullptr)
		{
			m_bFollow = false;
			m_vFollow = nullptr;
			return;
		}
		m_bFollow = true;
		m_vFollow = vFollow;
	}
	void CameraShake(float fTime, int iPower);
	Matrix m_matView;
	Matrix m_matProj; 
private:


	Vector2 m_vPos;
	bool m_bFollow = false;
	Vector2 * m_vFollow = nullptr;
	Vector2 m_vSize;


	float m_fShakeTime;
	float m_fTime = 0.f;
	int m_iShakePower = 0;
	bool m_bShake = false;
};

#define CAMERA (*CCameraManager::GetInstance())