#pragma once

class CSound
{
public:
	CSound(DWORD _DeviceID);
	~CSound();
private:
	DWORD m_DeviceID;

public:
	MCI_STATUS_PARMS     mciStatus; //파일의 상태
	DWORD GetDeviceID() { return m_DeviceID; }
};
