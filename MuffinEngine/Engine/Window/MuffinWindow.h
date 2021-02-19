#pragma once

class GLFWwindow;
class MuffinWindow
{
private:
	GLFWwindow* m_pWindow;
	n32 m_nWindowWidth;
	n32 m_nWindowHigh;
	tstring m_strWindowTitle;

public:
	MuffinWindow();
	~MuffinWindow();

	tbool InitWindow(n32 a_nWinWidth, n32 a_nWinHigh, const tcchar* a_strWinName);
	void DrawWindow();
	void Clear();
	tbool WindowShouldClose();

	T_INLINE GLFWwindow* GetGLFWWindow() { return this->m_pWindow; }
	T_INLINE n32 GetWindowWidth() { return this->m_nWindowWidth; }
	T_INLINE n32 GetWindowHeight() { return this->m_nWindowHigh; }
};


