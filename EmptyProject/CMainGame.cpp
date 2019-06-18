#include "DXUT.h"
#include "CMainGame.h"
#include "CLoadingScene.h"
#include "CMainScene.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Init()
{


	SCENE.AddScene("S_LOADING", new CLoadingScene());
	SCENE.AddScene("S_MAIN", new CMainScene());

	SCENE.ChangeScene("S_LOADING");
}
void CMainGame::Update()
{
	TIME.Update();

	INPUT.Update();

	OBJECT.Update();

	CAMERA.Update();

	SCENE.Update();
}

void CMainGame::Render()
{
	CAMERA.SetTransform();

	IMAGE.Begin(FALSE);

	SCENE.Render();

	OBJECT.Render();

	IMAGE.End();

	IMAGE.Begin(TRUE);

	TCHAR FPS_MSG[50];
	
	swprintf(FPS_MSG, L"FPS : %.1f", DXUTGetFPS());
	IMAGE.PrintText(FPS_MSG, Vector2(0, 0), 100, 0.f, false, D3DCOLOR_ARGB(255, 100, 100, 100));
	
	IMAGE.End();
}

void CMainGame::Release()
{
	CInputManager::ReleaseInstance();
	CImageManager::ReleaseInstance();
	CObjectManager::ReleaseInstance();
	CSceneManager::ReleaseInstance();
	CTimeManager::ReleaseInstance();
	CDataManager::ReleaseInstance();
	CSoundManager::ReleaseInstance();
	CCameraManager::ReleaseInstance();
}

void CMainGame::OnResetDevice()
{
	IMAGE.OnResetDevice();
}

void CMainGame::OnLostDevice()
{
	IMAGE.OnLostDevice();
}
