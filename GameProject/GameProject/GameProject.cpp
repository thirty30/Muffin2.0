// GameProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/Muffin.h"
#include "Test.h"

int main()
{
    AddComponent<Test>();
    AddComponent<Camera>();
}
