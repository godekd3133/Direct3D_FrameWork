#include "stdafx.h"
#include "KOI_Math.h"
#include "../../EmptyProject/stdafx.h"
using namespace Math;
bool Math::CheckCollision(const Rect & _reRect, const Vector2 & _vPos)
{
	return (_reRect.Left < _vPos.x &&
		_reRect.Top < _vPos.y &&
		_reRect.Right > _vPos.x &&
		_reRect.Bottom > _vPos.y);
}

bool Math::CheckCollision(const Vector2 & _vPos, const Rect & _reRect)
{
	return CheckCollision(_reRect, _vPos);
}
bool Math::CheckCollision(const Rect & _reRect01, const Rect & _reRect02)
{
	return (_reRect01.Left < _reRect02.Right &&
		_reRect01.Top <  _reRect02.Bottom &&
		_reRect01.Right > _reRect02.Left &&
		_reRect01.Bottom > _reRect02.Bottom);
}

bool Math::OBBCheckCollision(const Rect & _reRect01, float _fRot01, const Rect & _reRect02, float _fRot02)
{
	Vector2 dist = GetDistanceVector(_reRect01, _reRect02);
	Vector2 vec[4] = { GetHeightVector(_reRect01,_fRot01), GetHeightVector(_reRect02,_fRot02), GetWidthVector(_reRect01,_fRot01), GetWidthVector(_reRect02,_fRot02) };
	


	Vector2 unit;
	for (int i = 0; i < 4; i++) {
		double sum = 0;
		unit = GetUnitVector(vec[i]);
		for (int j = 0; j < 4; j++) {
			sum += absDotVector(vec[j], unit);
		}
		if (absDotVector(dist,unit) > sum) {
			return false;
		}
	}
	return true;
}

double Math::absDotVector(Vector2 a, Vector2 b)
{
	return abs(a.x * b.x + a.y * b.y);
}

double Math::DegToRad(double deg)
{
	return deg / 180 * 3.141592;
}

double Math::RadToDeg(double rad)
{
	return rad * 180 / 3.141592;
}

Vector2 Math::GetDistanceVector(Rect a, Rect b)
{
	Vector2 ret;
	ret.x = (a.Left + (a.Right - a.Left) / 2) - (b.Left + (b.Right - b.Left) / 2);
	ret.y = (a.Top + (a.Bottom - a.Top) / 2) - (b.Top + (b.Bottom - b.Top) / 2);
	return ret;
}

Vector2 Math::GetHeightVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Bottom - a.Top) * cos(DegToRad(_fRot -90)) / 2;
	ret.y = (a.Bottom - a.Top) * sin(DegToRad(_fRot -90)) / 2;
	return ret;
}

Vector2 Math::GetWidthVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Right - a.Left) * cos(DegToRad(_fRot)) / 2;
	ret.y = (a.Right - a.Left) * sin(DegToRad(_fRot)) / 2;
	return ret;
}

Vector2 Math::GetUnitVector(Vector2 a)
{
	Vector2 ret;
	double size;
	size = sqrtf(pow(a.x, 2) + pow(a.y, 2));
	ret.x = a.x / size;
	ret.y = a.y / size;
	return ret;
}

Vector2 Math::RotateVector(Vector2 _vCenter, Vector2 _vPoint, float _fDegree)
{
		float rad = Math::DegToRad(_fDegree);
		float rx = (_vPoint.x - _vCenter.x)*cosf(rad) - (_vPoint.y - _vCenter.y)*sinf(rad) + _vCenter.x;
		float ry = (_vPoint.x - _vCenter.x)*sinf(rad) + (_vPoint.y - _vCenter.y)*cosf(rad) + _vCenter.y;
		return { rx , ry };
}

Math::Rect::Rect()
{
}

Math::Rect::Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom)
	: Left(_fLeft), Top(_fTop), Right(_fRight), Bottom(_fBottom)
{
}

Math::Rect::Rect(Vector2  _vPos, FLOAT _fWidth, FLOAT _fHeight)
	: Left(_vPos.x), Top(_vPos.y), Right(_vPos.x + _fWidth), Bottom(_vPos.y + _fHeight)
{

}

Math::Rect::Rect(RECT _reRect)
	: Rect((FLOAT)_reRect.left,
	(FLOAT)_reRect.top,
		(FLOAT)_reRect.right,
		(FLOAT)_reRect.bottom)
{
}

Math::Rect::Rect(Vector2 _vVertex[4])
{
	Left = _vVertex[0].x;
	Top = _vVertex[0].y;
	Right = _vVertex[2].x;
	Bottom = _vVertex[2].y;
}

void Math::Rect::Rotate(float _fDegree)
{
	float rad = Math::DegToRad(_fDegree);

	Vector2 _vVertex[4] = 
	{
	Math::RotateVector(GetCenter(), GetLT(),_fDegree),
	Math::RotateVector(GetCenter(), GetRT(), _fDegree),
	Math::RotateVector(GetCenter(), GetRB(),_fDegree),
	Math::RotateVector(GetCenter(), GetLB(), _fDegree)
	};
	

	//	float s = sinf(rad);
	//float c = cosf(rad);


	//Vector2 _vVertex[4];
	//_vVertex[0] =	Vector2(GetLT().x * c - (GetLT().y * s), GetLT().x * s + (GetLT().y * c));
	//_vVertex[1] =	Vector2(GetRT().x * c - (GetRT().y * s), GetRT().x * s + (GetRT().y * c));
	//_vVertex[2] =	Vector2(GetRB().x * c - (GetRB().y * s), GetRB().x * s + (GetRB().y * c));
	//_vVertex[3] =	Vector2(GetLB().x * c - (GetLB().y * s), GetLB().x * s + (GetLB().y * c));
	//
	Left = _vVertex[0].x;
	Top = _vVertex[0].y;
	Right = _vVertex[2].x;
	Bottom = _vVertex[2].y;
	//Rect::Rect(_vVertex);
}

Math::Rect::~Rect()
{
}


