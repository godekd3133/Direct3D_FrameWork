#pragma once

template <typename T>
class singleton
{
private:
	static T* p;
public:
	singleton() {}
	~singleton() {}
public:
	static T * GetInstance()
	{
		if (!p) p = new T;
		return p;
	}

	static void ReleaseInstance()
	{
		delete p;
		p = nullptr;
	}
};

template <class T>
T* singleton<T>::p = nullptr;