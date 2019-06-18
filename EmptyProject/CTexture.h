#pragma once
class CTexture 
{
public:
	CTexture();
	~CTexture();
public:
	LPDIRECT3DTEXTURE9 m_pTexture = NULL;
	D3DXIMAGE_INFO m_Info;

public:
	void Render(
		const Vector2& _vPos,
		const Vector2& _vScale,
		FLOAT _fDegree,
		Rect _reRect,
		Color _Color = D3DCOLOR_ARGB(255,255,255,255));


};

