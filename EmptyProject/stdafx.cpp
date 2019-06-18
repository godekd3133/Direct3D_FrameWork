#include "DXUT.h"

INT GetRandomNum(INT _Min, INT _Max)
{
	//시드 설정
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//분포 설정
	uniform_int_distribution<int> range(_Min, _Max);

	//값 추출
	return range(rnd);
}

FLOAT GetRandomNum(FLOAT _Min, FLOAT _Max)
{
	INT min = (INT)(_Min * 1000);
	INT max = (INT)(_Max * 1000);
	//시드 설정
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//분포 설정
	uniform_int_distribution<int> range(min, max);

	//값 추출
	return (FLOAT)(range(rnd) / 1000.f);
}

