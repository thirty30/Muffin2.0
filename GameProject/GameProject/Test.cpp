#include "Test.h"

CRTTIObject Test::_RTTI_Test(typeid(Test).hash_code(), Test::_RTTI_CreateSelf);

MuffinObject* Test::_RTTI_CreateSelf()
{
	return new Test();
}

