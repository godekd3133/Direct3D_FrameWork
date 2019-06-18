#include "DXUT.h"
#include "CImageManager.h"


CImageManager::CImageManager()
{
	D3DXCreateSprite(g_Device, &m_pSprite);
}


CImageManager::~CImageManager()
{
	for (auto& iter : m_mapTexture)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapTexture.clear();
	SAFE_RELEASE(m_pSprite);

}

void CImageManager::Begin(bool isInterface)
{
	if (TRUE == isInterface)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
	else m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void CImageManager::End()
{
	m_pSprite->End();
}

void CImageManager::ReBegin(bool isInterface)
{
	m_pSprite->End();
	if (TRUE == isInterface)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
	else m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void CImageManager::OnLostDevice()
{
	m_pSprite->OnLostDevice();
}

void CImageManager::OnResetDevice()
{
	m_pSprite->OnResetDevice();
}

CTexture * CImageManager::AddTexture(CONSTREF(string) _Key, CONSTREF(string) _Path)
{
	auto find = m_mapTexture.find(_Key);
	
	if (find == m_mapTexture.end())
	{
		CTexture * pTexture = new CTexture;
		
		if (S_OK == D3DXCreateTextureFromFileExA(
			g_Device,
			_Path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			0,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&pTexture->m_Info,
			NULL,
			&pTexture->m_pTexture))
		{
			m_mapTexture[_Key] = pTexture;
			return pTexture;
		}
		DEBUG_LOG("FAILED LOAD TEXTURE %s",_Path.c_str());
		return nullptr;
	}
	
	return find->second;
}

CTexture * CImageManager::FindTexture(CONSTREF(string) _Key)
{
	auto find = m_mapTexture.find(_Key);
	
	if (find != m_mapTexture.end())
	{
		return find->second;
	}
	return nullptr;
}

void CImageManager::PrintText(wstring _wsStr, const Vector2 & _vPos, int _iSize, float _fDegree, bool _bCenter, D3DCOLOR _Color)
{
	LPD3DXFONT pFont;
	D3DXMATRIX matWorld , matTrans, matRot;

	D3DXCreateFontW(DXUTGetD3D9Device(), _iSize, 0, 0, 1,
		FALSE, HANGUL_CHARSET, 0, 0, 0, L"¸¼Àº °íµñ Bold", &pFont);

	D3DXMatrixRotationZ(&matRot, Math::DegToRad(_fDegree));

	if (!_bCenter)
		D3DXMatrixTranslation(&matTrans, _vPos.x, _vPos.y, 0);
	else
		D3DXMatrixTranslation(&matTrans, _vPos.x - _iSize * (_wsStr.size() * 0.25), _vPos.y - _iSize / 2.f, 0);

	matWorld = matRot * matTrans;
	m_pSprite->SetTransform(&matWorld);
	pFont->DrawTextW(m_pSprite, _wsStr.c_str(), _wsStr.size(), NULL, DT_CENTER | DT_NOCLIP, _Color);
	SAFE_RELEASE(pFont);
}

vector<CTexture*> CImageManager::MakeVecTex(CONSTREF(string) _Key)
{
	vector<CTexture*> vecTexture;
	
	for(int i = 1; ; i++)
	{
		char Key[100];
		sprintf(Key, "%s (%d)", _Key.c_str(),i);

		auto Find = FindTexture(Key);
		if (Find == nullptr)
			break;
		
		vecTexture.push_back(Find);
	}

	if (vecTexture.empty() == true)
	{
		DEBUG_LOG("VECTEXTURE IS EMPTY : %s", _Key.c_str());
	}
	
	return vecTexture;	
}


void CImageManager::RenderLine(Vector2 _vStart, Vector2 _vEnd, float _fWidth, D3DCOLOR _Color)
{
	Vector2 vPos[2] = { _vStart,_vEnd };
	ID3DXLine *Line;

	
	//	Matrix a;
//	D3DXMatrixRotationZ(&a, Math::DegToRad(70));
	D3DXCreateLine(g_Device, &Line);
	Line->SetWidth(_fWidth);

	Line->SetAntialias(true);
	Line->Begin(); 
	//Line->DrawTransform(vPos, 2, &a, _Color);
	Line->Draw(vPos, 2, _Color);
	Line->End();
	Line->Release();
}

void CImageManager::Render(
	CTexture * _pTexture,
	const Vector2& _vPos,
	const Vector2& _vScale,
	FLOAT _fDegree,
	Rect _reRect,
	Color _Color)
{
	Vector3 vCenter = Vector3(_pTexture->m_Info.Width / 2.f, _pTexture->m_Info.Height / 2.f, 0.f);
				   
	Matrix matWorld, matScale, matRotation, matTransformation;

	D3DXMatrixScaling(&matScale, _vScale.x, _vScale.y, 1.f);

	D3DXMatrixRotationZ(&matRotation, D3DXToRadian(_fDegree));
	
	D3DXMatrixTranslation(&matTransformation, _vPos.x, _vPos.y, 0.f);

	matWorld = matScale * matRotation * matTransformation;

	m_pSprite->SetTransform(&matWorld);

	m_pSprite->Draw(_pTexture->m_pTexture, &(RECT)_reRect, &vCenter ,nullptr, _Color);

}


