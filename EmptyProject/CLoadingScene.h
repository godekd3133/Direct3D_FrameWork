#pragma once
#include "CScene.h"
struct strbundle
{
public:
	strbundle(CONSTREF(string) _Key, CONSTREF(string) _Path) : m_Key(_Key),m_Path(_Path){ }
	~strbundle() {}
public:
	string m_Key;
	string m_Path;
};
class CLoadingScene : public CScene
{
public:
	CLoadingScene();
	~CLoadingScene();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void AddLoadList(CONSTREF(string) _Key, CONSTREF(string) _Path, int _iSize = 1);
private:
	list<strbundle> m_LoadList;
	thread m_Thread;
	int m_LoadSize;
	int m_LoadMax;
	static void LoadFirst(list<strbundle>& _LoadList);
	CObject * m_pObject = nullptr;
};

