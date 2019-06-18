#pragma once
class CTimer;
class CAnimator
{
public:
	CAnimator();
	~CAnimator();

public:
	void Init(const string& _Key, float _fDelay , bool _bLoop);
	void Update();
	void Render();
	void Release();
	// 재생 딜레이
	float m_fDelay;

	// 반복 여부 FALSE 일경우 한번만 돌고 0프레임으로 가고 재생 정지
	bool m_bLoop;

	// 애니메이션 재생중인지 
	bool m_bActive;

	// 인덱스 기준 현재 프레임
	int m_iFrame = 0;

	// 인덱스 기준 최대 프레임
	int m_iMaxFrame;
	CTexture * GetFrameTexture() { return m_Textures[m_iFrame]; }
private:
	vector<CTexture*> m_Textures;
	CTimer * m_pTimer = nullptr;

};

