#include "pch.h"
#include "./MuffinWindow.h"


MuffinWindow::MuffinWindow()
{
	this->m_nWindowWidth = 0;
	this->m_nWindowHigh = 0;
	this->m_strWindowTitle = "";
	this->m_pWindow = NULL;
}

MuffinWindow::~MuffinWindow()
{

}

tbool MuffinWindow::InitWindow(n32 a_nWinWidth, n32 a_nWinHigh, const tcchar* a_strWinName)
{
	return true;
}

void MuffinWindow::DrawWindow()
{

}

void MuffinWindow::Clear()
{

}

tbool MuffinWindow::WindowShouldClose()
{
	return false;
}
