#include "DXUT.h"
#include "CMainScene.h"
#include "CPlayer.h"

CMainScene::CMainScene()
{
}


CMainScene::~CMainScene()
{
}

void CMainScene::Init()
{
	m_pPlayer01 = OBJECT.AddObject<CPlayer>(); 
	m_pPlayer01->Init();
	m_pPlayer01->Translation->m_fRotation = 70;
	m_pPlayer01->Translation->m_vPosition = Vector2(WINSIZEX / 2.F, WINSIZEY / 2.F);


	m_pPlayer02 = OBJECT.AddObject<CPlayer>();
	m_pPlayer02->Init();
	m_pPlayer02->Translation->m_fRotation = 40;
	
}

void CMainScene::Update()
{

	
	if (INPUT.KeyPress(VK_LEFT))  	m_pPlayer01->Translation->m_vPosition.x -= 300 * TIME.DeltaTime;
	if (INPUT.KeyPress(VK_RIGHT))  	m_pPlayer01->Translation->m_vPosition.x += 300 * TIME.DeltaTime;
	if (INPUT.KeyPress(VK_UP))  	m_pPlayer01->Translation->m_vPosition.y -= 300 * TIME.DeltaTime;
	if (INPUT.KeyPress(VK_DOWN))  	m_pPlayer01->Translation->m_vPosition.y += 300 * TIME.DeltaTime;
	if (INPUT.KeyPress('1'))		m_pPlayer01->Translation->m_fRotation -= 100 * TIME.DeltaTime;
	if (INPUT.KeyPress('2'))		m_pPlayer01->Translation->m_fRotation += 100 * TIME.DeltaTime;


	if (INPUT.KeyPress('A'))  	m_pPlayer02->Translation->m_vPosition.x -= 300 * TIME.DeltaTime;
	if (INPUT.KeyPress('D'))  	m_pPlayer02->Translation->m_vPosition.x += 300 * TIME.DeltaTime;
	if (INPUT.KeyPress('W'))  	m_pPlayer02->Translation->m_vPosition.y -= 300 * TIME.DeltaTime;
	if (INPUT.KeyPress('S'))  	m_pPlayer02->Translation->m_vPosition.y += 300 * TIME.DeltaTime;
	if (INPUT.KeyPress('3'))		m_pPlayer02->Translation->m_fRotation -= 100 * TIME.DeltaTime;
	if (INPUT.KeyPress('4'))		m_pPlayer02->Translation->m_fRotation += 100 * TIME.DeltaTime;
}

void CMainScene::Render()
{
	//Vector2 vec[4] = { 
	//	GetHeightVector(m_pPlayer01->GetComponent<CBoxCollider>()->m_reRect,m_pPlayer01->Translation->m_fRotation), 
	//	GetHeightVector(m_pPlayer02->GetComponent<CBoxCollider>()->m_reRect,m_pPlayer02->Translation->m_fRotation),
	//	GetWidthVector(m_pPlayer01->GetComponent<CBoxCollider>()->m_reRect,m_pPlayer01->Translation->m_fRotation),
	//	GetWidthVector(m_pPlayer02->GetComponent<CBoxCollider>()->m_reRect,m_pPlayer02->Translation->m_fRotation) };
	//IMAGE.RenderLine(vec[0], vec[1], 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	////IMAGE.RenderLine({ WINSIZEX / 2.f,0 }, { 0,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	////IMAGE.RenderLine({ WINSIZEX / 2.f,0 }, { 0,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	////IMAGE.RenderLine({ WINSIZEX / 2.f,0 }, { 0,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));

	//
	//IMAGE.RenderLine({ WINSIZEX / 2.f,0 }, { 0,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	//IMAGE.RenderLine({ WINSIZEX / 2.f,0}, { WINSIZEX,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	//IMAGE.RenderLine({ WINSIZEX / 2.f,WINSIZEY }, { 0,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
	//IMAGE.RenderLine({ WINSIZEX / 2.f,WINSIZEY }, { WINSIZEX,WINSIZEY / 2.F }, 2, D3DCOLOR_ARGB(255, 0, 0, 0));
}

void CMainScene::Release()
{
}
