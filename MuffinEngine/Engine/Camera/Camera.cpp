#include "pch.h"
#include "Camera.h"

CRTTIObject Camera::_RTTI_Camera(typeid(Camera).hash_code(), Camera::_RTTI_CreateSelf);

MuffinObject* Camera::_RTTI_CreateSelf()
{
	return new Camera();
}
