#pragma once
#include "singleton.h"
class CImageManager :
	public singleton< CImageManager>
{
public:
	CImageManager();
	~CImageManager();
private:
	LPD3DXSPRITE m_pSprite = NULL;
	map<string, CTexture*> m_mapTexture;
public:
	void Begin(bool isInterface);
	void End();
	void ReBegin(bool isInterface);
	void OnLostDevice();
	void OnResetDevice();
public:
	CTexture * AddTexture(CONSTREF(string)_Key, CONSTREF(string) _Path);
	CTexture * FindTexture(CONSTREF(string)_Key);
	vector<CTexture*> MakeVecTex(CONSTREF(string)_Key);
	void PrintText(wstring _wsStr,const Vector2 & _vPos, int _iSize,float _fDegree,bool _bCenter,D3DCOLOR _Color);

	CTexture * operator [](const string& _Key)
	{
		return FindTexture(_Key);
	}

	void RenderLine(Vector2 _vStart,Vector2 _vEnd, float _fWidth, D3DCOLOR _Color)
; public:
	void Render(
		CTexture * _pTexture,
		const Vector2& _vPos,
		const Vector2& _vScale,
		FLOAT _fDegree,
		Rect _reRect,
		Color _Color);



};

#define IMAGE (*CImageManager::GetInstance())
