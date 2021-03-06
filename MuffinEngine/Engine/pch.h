// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

/////////////////////////////////////////////////////////////////////////////////

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <Thread>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////

#include "Core/TypeDefine.h"

#endif //PCH_H
