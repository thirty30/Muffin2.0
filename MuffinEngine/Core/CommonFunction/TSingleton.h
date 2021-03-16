#pragma once

#define T_DECLARE_SINGLETON(className)						\
	public: \
		static className& GetSingleton() \
		{ \
			if (_instance == nullptr) \
			{\
				_instance = new className();\
			}\
			return *_instance; \
		} \
	private: \
		static className* _instance;\
		\
		className() = default; \
		~className() = default; \
		className(const className& other) = default; \
		className& operator= (const className& other) = default;

#define T_IMPLEMENT_SINGLETON(className)						\
	className* className::_instance = nullptr;

/*
template<typename T>
class CSingleton
{
protected:
	static T* m_pSingleton;

public:
	CSingleton()
	{
		m_pSingleton = static_cast<T*>(this);
	}
	virtual ~CSingleton()
	{
		m_pSingleton = NULL;
	}
	static T& GetSingleton()
	{
		return *m_pSingleton;
	}
	static T* GetSingletonPtr()
	{
		return m_pSingleton;
	}
};

#define T_IMPLEMENT_SINGLETON( SingletonClass )\
	template<> SingletonClass* CSingleton<SingletonClass>::m_pSingleton = NULL;
*/

