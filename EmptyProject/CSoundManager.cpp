#include "DXUT.h"
#include "CSoundManager.h"


CSoundManager::CSoundManager()
{
}



CSoundManager::~CSoundManager()
{
	for (auto& iter : m_Sounds)
	{
		mciSendCommand(iter.second->GetDeviceID(), MCI_CLOSE, 0, NULL);
		SAFE_DELETE(iter.second);
	}
	m_Sounds.clear();
}

CSound * CSoundManager::AddSound(CONSTREF(string) _Key, CONSTREF(string) _Path)
{
	auto find = m_Sounds.find(_Key);
	if (find == m_Sounds.end())
	{
		mciOpen.lpstrElementName = _Path.c_str();
		mciOpen.lpstrDeviceType = "mpegvideo";

		mciSendCommandA(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);
		DWORD DevicID = mciOpen.wDeviceID;
		CSound * pSound = new CSound(DevicID);
		m_Sounds[_Key] = pSound;
		return pSound;
		
	}
	return nullptr;
}

CSound * CSoundManager::FindSound(CONSTREF(string) _Key)
{
	auto find = m_Sounds.find(_Key);
	if (find == m_Sounds.end())
		return nullptr;
	
	return find->second;
}

void CSoundManager::Play(CONSTREF(string) _Key, bool _bLoop)
{
	auto find = m_Sounds.find(_Key);

	if (find != m_Sounds.end())
	{
		mciSendCommand(find->second->GetDeviceID(), MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&mciPlay);
		mciSendCommand(find->second->GetDeviceID(), MCI_PLAY, (_bLoop == TRUE ? MCI_DGV_PLAY_REPEAT : MCI_NOTIFY), (DWORD)(LPVOID)&mciPlay);
	}
}

void CSoundManager::Stop(CONSTREF(string) _Key)
{
	auto find = m_Sounds.find(_Key);
	if (find != m_Sounds.end())
	{
		mciSendCommand(find->second->GetDeviceID(), MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&mciPlay);
	}
}
