#pragma once
#include "CComponent.h"
class CTransform :
	public CComponent
{
public:
	CTransform(CObject * _pObj);
	~CTransform();
public:
	Vector2 m_vPosition;
	Vector2 m_vScale;
	FLOAT m_fRotation;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	
public:
//	void SetPosition(Vector2 _vPos)			{ m_vPosition = _vPos; }
//	void SetPosition(float _fX, float _fY)	{ m_vPosition = Vector2(_fX, _fY); }
//	
//	void SetScale(Vector2 _vScale)		{ m_vScale = _vScale; }
//	void SetScale(float _fX, float _fY) { m_vScale = Vector2(_fX, _fY); }
//	
//	void SetRotation(float _fRot) { m_fRotation = _fRot; }
//	
//	void SetRotationCenter(const Vector2& _vCenter) { m_vRotationCenter = _vCenter; }
//	void SetRotationCenter(float _fX,float _fY)		{ m_vRotationCenter = Vector2(_fX,_fY); }
//public:
//	Vector2 GetPosition()		{ return m_vPosition; }
//	Vector2 GetScale()			{ return m_vScale; }
//	float	GetRotation()		{ return m_fRotation; }
//	Vector2 GetRotationCenter() { return m_vRotationCenter; }
};

