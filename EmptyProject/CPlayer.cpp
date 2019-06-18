#include "DXUT.h"
#include "CPlayer.h"
CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	 
}

void CPlayer::Init()
{
	//m_Animations[PLAYER_STATUS::Run] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::Slide] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::Jump] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::DoubleJump] = new CAnimation("RUN", 0.05f, true);
	this->AddComponent<CRenderer>()->Init();

	this->AddComponent<CAnimation>()->Init();

	this->GetComponent<CAnimation>()->AddAnimator("RUN", "Run", 0.1f, true);

	this->GetComponent<CAnimation>()->SetHandleAnimator("RUN");

	this->AddComponent<CBoxCollider>()->Init();

	
	//this->GetComponent<CRenderer>()->
}

void CPlayer::Update()
{
	this->GetComponent<CBoxCollider>()->SetCollisionBox(this->GetComponent<CRenderer>()->m_rRect);

	// DEBUG_LOG("player update");
	//GetComponent<CCollider>()->Update(m_vPosition);
	//_Animations[m_Status]->Update();
	//this->Translation->m_vPosition.x =
	//if (INPUT.KeyPress(VK_LEFT)) 
	//if (INPUT.KeyPress(VK_RIGHT)) m_vPosition.x += 400 * TIME.DeltaTime;
}

void CPlayer::Render()
{

}

void CPlayer::OnCollisionEnter(CObject * _pObject)
{
}

void CPlayer::OnCollisionStay(CObject * _pObject)
{
}

void CPlayer::OnCollisionExit(CObject * _pObject)
{
}

void CPlayer::OnTriggerEnter(CObject * _pObject)
{
	
	if (_pObject->m_Tag == Player)
	{
	//	DEBUG_LOG("%d", _pObject->m_Tag);
		DEBUG_LOG("Enter");
	}
}

void CPlayer::OnTriggerStay(CObject * _pObject)
{
	if (_pObject->m_Tag == Player)
	{
		DEBUG_LOG("Stay");
	}
}

void CPlayer::OnTriggerExit(CObject * _pObject)
{
	DEBUG_LOG("¤¾¤·2");

}


void CPlayer::Release()
{
	//SAFE_DELETE(m_pAnimation);
}

