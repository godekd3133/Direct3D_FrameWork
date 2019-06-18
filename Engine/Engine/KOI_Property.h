#pragma once
#include "stdafx.h"
#define KOI_BASE_ENGINE_DIRECTX9 0 // DirectX9
#define KOI_BASE_ENGINE_COCOS2DX 1 // Cocos2d-x

// 사용중인 주 엔진
#define KOI_BASE_ENGINE KOI_BASE_ENGINE_DIRECTX9


// 해상도
static UINT g_Window_Width = 1280;
static UINT g_Window_Height = 720;
static BOOL g_IsWindowMode = true;
