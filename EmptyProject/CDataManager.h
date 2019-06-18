#pragma once
#include "singleton.h"
class CDataManager :
	public singleton<CDataManager>
{
public:
	CDataManager();
	~CDataManager();
private:
	map<string, void * > m_Datas;
public:
	template <typename T>
	T * GetData(CONSTREF(string) _Key)
	{
		auto Find = m_Datas.find(_Key);
		if (Find == m_Datas.end())
		{
			DEBUG_LOG("GetData Func Error : could not find data");
			return nullptr;
		}
		return (T*)Find->second;
	}

	template <typename T>
	T * AddData(CONSTREF(string) _Key, CONSTPTR(T) _pData)
	{
		auto Find = m_Datas.find(_Key);
		if (Find == m_Datas.end())
		{
			m_Datas.insert(make_pair(_Key, _pData));
			return _pData;
		}
		else
		{
			SAFE_DELETE(_pData);
			return (T*)Find->second;
		}
	}

	void DeleteData(CONSTREF(string) _Key)
	{
		auto Find = m_Datas.find(_Key);
		if (Find != m_Datas.end())
			SAFE_DELETE(Find->second);
	}
};




#define DATA (*CDataManager::GetInstance())