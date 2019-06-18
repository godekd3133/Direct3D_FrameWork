#include "DXUT.h"
#include "CLoadingScene.h"

CLoadingScene::CLoadingScene()
{
}


CLoadingScene::~CLoadingScene()
{
}

void CLoadingScene::Init()
{
	AddLoadList("Run", "Run",4);

	
	
	
	m_LoadMax = m_LoadList.size();
	m_LoadSize = 0;
	DEBUG_LOG("Now Loading Resources...");
}

void CLoadingScene::Update()
{
	if (m_LoadList.empty() == FALSE)
	{
		m_Thread = thread(&CLoadingScene::LoadFirst,m_LoadList);

		m_Thread.join();
		m_LoadList.pop_front();
		m_LoadSize++;
		DEBUG_LOG("Loading Status %d / %d (%.1f%%)",m_LoadSize,m_LoadMax,100.f *  (float)m_LoadSize/ (float)m_LoadMax);
	}
	else
	{
		SCENE.ChangeScene("S_MAIN");
	}
}

void CLoadingScene::Render()
{
}

void CLoadingScene::Release()
{
}

void CLoadingScene::AddLoadList(CONSTREF(string) _Key, CONSTREF(string) _Path, int _iSize)
{
	if (_iSize == 1)
	{
		char Path[100];
		sprintf(Path, "../resource/%s.png", _Path.c_str());
		m_LoadList.push_back(strbundle(_Key, Path));
	}
	else
	{
		for (int i = 1; i <= _iSize; i++)
		{
			char Path[100];
			char Key[100];
			sprintf(Path, "../resource/%s (%d).png", _Path.c_str(),i);
			sprintf(Key, "%s (%d)", _Key.c_str(),i);

			m_LoadList.push_back(strbundle(Key, Path));
		}
	}
}

void CLoadingScene::LoadFirst(list<strbundle>& _LoadList)
{
	auto Handle = _LoadList.front();
	IMAGE.AddTexture(Handle.m_Key, Handle.m_Path);
}
