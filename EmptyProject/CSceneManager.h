#pragma once
#include "singleton.h"
#include "CScene.h"
class CSceneManager :
	public singleton< CSceneManager>
{
public:
	CSceneManager();
	~CSceneManager();
public:
	void Update();
	void Render();
	CScene * AddScene(CONSTREF(string) _Key, CScene*_pScene);
	CScene * ChangeScene(CONSTREF(string) _Key);
private:
	CScene * m_pCurScene = nullptr;
	CScene * m_pNextScene = nullptr;
	map<string, CScene*> m_mapScene;
public:

};

#define SCENE (*CSceneManager::GetInstance())

