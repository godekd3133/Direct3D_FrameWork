#pragma once
#include "stdafx.h"
namespace Math
{
	static float PI = 3.141592f;

	using Vector2 = KOI_DEF_TYPEDEFINE_VECTOR2D;
	using Vector3 = KOI_DEF_TYPEDEFINE_VECTOR3D;
	using Vector4 = KOI_DEF_TYPEDEFINE_VECTOR4D;
	using Matrix = KOI_DEF_TYPEDEFINE_MAXTRIX4;


	class Rect
	{
	public:
		FLOAT Left;
		FLOAT Top;
		FLOAT Right;
		FLOAT Bottom;
	public:
		Rect();
		~Rect();
		Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom);
		Rect(Vector2 _vPos, FLOAT _fWidth, FLOAT _fHeight);
		Rect(RECT _reRect);
		Rect(Vector2 _vVertex[4]);

		operator RECT()
		{
			return
			{
				(LONG)Left,
				(LONG)Top,
				(LONG)Right,
				(LONG)Bottom
			};
		}
		void Rotate(float _fDegree);
		Vector2 GetLT() { return Vector2(Left, Top); }
		Vector2 GetRT() { return Vector2(Right, Top); }
		Vector2 GetLB() { return Vector2(Left, Bottom); }
		Vector2 GetRB()	{ return Vector2(Right, Bottom); }
		Vector2 GetCenter() { return Vector2(Left + (Right - Left) /2, Top + (Bottom - Top)/2); }
	};

	//사각형안에 벡터가 속해있는지 확인해주는 함수
	bool CheckCollision(const Rect& _reRect, const Vector2& _vPos);
	
	//사각형안에 벡터가 속해있는지 확인해주는 함수
	bool CheckCollision(const Vector2& _vPos, const Rect& _reRect);


	bool CheckCollision(const Rect& _reRect01, const Rect& _reRect02);

	bool OBBCheckCollision(const Rect& _reRect01, float _fRot01, const Rect& _reRect02, float _fRot02);
	//vector inner
	double absDotVector(Vector2 a, Vector2 b);
	//deg -> rad
	__inline double DegToRad(double deg);

	//deg -> rad 
	__inline double RadToDeg(double rad);

	//distance vector
	Vector2 GetDistanceVector(Rect a, Rect b);

	//height vector
	Vector2 GetHeightVector(Rect a, float _fRot);	 

	//width vector
	Vector2 GetWidthVector(Rect a, float _fRot);

	//unit vector
	Vector2 GetUnitVector(Vector2 a);

	Vector2 RotateVector(Vector2 _vCenter,
		Vector2 _vPoint,
		float _fDegree);
}
