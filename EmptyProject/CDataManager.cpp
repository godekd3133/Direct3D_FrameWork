#include "DXUT.h"
#include "CDataManager.h"


CDataManager::CDataManager()
{
}


CDataManager::~CDataManager()
{
	for (auto& iter : m_Datas)
	{
		SAFE_DELETE(iter.second);
	}
	m_Datas.clear();
}
