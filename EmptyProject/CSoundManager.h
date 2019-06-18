#pragma once
#include "singleton.h"
#include "CSound.h"
class CSoundManager :
	public singleton< CSoundManager>
{
public:
	CSoundManager();
	~CSoundManager();
private:
	MCI_OPEN_PARMSA      mciOpen;
	MCI_PLAY_PARMS       mciPlay; //파일을 재생


	map <string, CSound*> m_Sounds;
public:
	CSound * AddSound(CONSTREF(string) _Key, CONSTREF(string) _Path);
	CSound * FindSound(CONSTREF(string) _Key);

	void Play(CONSTREF(string) _Key,bool _bLoop);
	void Stop(CONSTREF(string) _Key);

};

#define SOUND (*CSoundManager::GetInstance())

