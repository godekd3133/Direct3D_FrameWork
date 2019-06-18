#include "DXUT.h"
#include "CSceneManager.h"


CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
	if(m_pCurScene)
	m_pCurScene->Release();
	
	if(m_pNextScene)
	m_pNextScene->Release();
	
	for (auto iter : m_mapScene)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapScene.clear();
}

void CSceneManager::Update()
{
	if (m_pCurScene)
		m_pCurScene->Update();

	if (m_pNextScene)
	{
		if (m_pCurScene)
			m_pCurScene->Release();
		m_pCurScene = m_pNextScene;
		m_pNextScene = nullptr;
		m_pCurScene->Init();
	}
}

void CSceneManager::Render()
{
	if (m_pCurScene)
		m_pCurScene->Render();
}

CScene * CSceneManager::AddScene(CONSTREF(string) _Key, CScene * _pScene)
{
	auto find = m_mapScene.find(_Key);

	if (find == m_mapScene.end())
	{
		m_mapScene[_Key] = _pScene;
		return _pScene;
	}
	else
	{
		SAFE_DELETE(_pScene);
		return nullptr;
	}
}

CScene * CSceneManager::ChangeScene(CONSTREF(string) _Key)
{
	m_pNextScene = m_mapScene.find(_Key)->second;
	return m_pNextScene;
}
