#pragma once
#include "../Engine/Engine/stdafx.h"

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <random>
#include <string>
#include <functional>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <Psapi.h>
#include <mmsystem.h>
#include <Digitalv.h>
//#include "DXUT/Optional/SDKsound.h"
//#include "DXUT/Optional/SDKwavefile.h"
//#pragma comment (lib, "dsound.lib")

#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "Psapi.lib")


using namespace std;
using namespace chrono;
using namespace Math;
using Second = chrono::duration<double>;
// hypothetical C++2x code
using Color = D3DCOLOR;
using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;
using TimePoint = system_clock::time_point;

CONST FLOAT WINSIZEX = 1280.f;
CONST FLOAT WINSIZEY = 960.f;
static bool WINDOWED = true;

INT GetRandomNum(INT _Min, INT _Max);
FLOAT GetRandomNum(FLOAT _Min, FLOAT _Max);

template <typename T>
void Lerp(T* target, const T& start, const T& end, float speed)
{
	*target = start + (end - start) * speed;
}

#if _DEBUG
#pragma comment (linker , "/entry:wWinMainCRTStartup /subsystem:console")
#endif

#define g_Device DXUTGetD3D9Device()

#if _DEBUG || DEBUG
#define DEBUG_LOG cout << endl; cout << "DEBUG_LOG :: "; printf        
#else 
#define DEUBG_LOG
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#define CONSTREF(ty)  CONST ty&
#define CONSTPTR(ty)  CONST ty*
#define LP(var) (*var)

#define SCREEN_CENTER Vector2(WINSIZEX/2.f,WINSIZEY/2.f)
#define COLOR_BASIC D3DCOLOR_ARGB(255,255,255,255)

#include "CTexture.h"
#include "CAnimation.h"
#include "CObject.h"
#include "CDataManager.h"
#include "CInputManager.h"
#include "CImageManager.h"

#include "CObjectManager.h"

#include "CTimer.h"
#include "CTimeManager.h"

#include "CCameraManager.h"

#include "CSceneManager.h"
#include "CSoundManager.h"

 
