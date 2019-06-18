#pragma once

template <typename T>
class singleton
{
	static T * Instance;
	
	static T * GetInstance()
	{
		if (!Instance)
		{
			Instance = new T();
		}
		return Instance;
	}
	static void ReleaseInstance()
	{
		if (Instance)
		{
			delete Instance;
			Instance = nullptr;
		}
	}
};

template <class T>
T * singleton<T>::Instance = nullptr;