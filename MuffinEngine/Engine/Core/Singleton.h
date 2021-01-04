#pragma once

#define DECLARE_SINGLETON(className)						\
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

#define IMPLEMENT_SINGLETON(className)						\
	className* className::_instance = nullptr;