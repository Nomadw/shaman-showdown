#pragma once

#include <windows.h>	// need this file if you want to create windows etc
#include <gl/gl.h>		// need this file to do graphics with opengl
#include <gl/glu.h>		// need this file to set up a perspective projection easily


// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")

// function prototypes:
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	int windowWidth = 800;
	int windowHeight = 600;
	int windowTopLeftX = 50;
	int windowTopLeftY = 50;

	MSG msg;				

#pragma region  <-- click the plus/minus sign to collapse/expand!

	WNDCLASS myWindowClass;
	myWindowClass.cbClsExtra = 0;											// no idea
	myWindowClass.cbWndExtra = 0;											// no idea
	myWindowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// background fill black
	myWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// arrow cursor       
	myWindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// type of icon to use (default app icon)
	myWindowClass.hInstance = hInstance;									// window instance name (given by the OS when the window is created)   
	myWindowClass.lpfnWndProc = WndProc;									// window callback function - this is our function below that is called whenever something happens
	myWindowClass.lpszClassName = TEXT("my window class name");				// our new window class name
	myWindowClass.lpszMenuName = 0;											// window menu name (0 = default menu?) 
	myWindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;				// redraw if the window is resized horizontally or vertically, allow different context for each window instance

	RegisterClass(&myWindowClass);

	RECT rect;
	SetRect(&rect, windowTopLeftX,
		windowTopLeftY,
		windowTopLeftX + windowWidth,
		windowTopLeftY + windowHeight);

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	HWND myWindow = CreateWindow(TEXT("my window class name"),
		TEXT("CT4TOGA Coursework Template"),
		WS_OVERLAPPEDWINDOW,					
		windowTopLeftX, windowTopLeftY,		
		windowWidth, windowHeight,				
		NULL, NULL,								
		hInstance, NULL);		

	if (myWindow == NULL)
	{
		FatalAppExit(NULL, TEXT("CreateWindow() failed!"));
	}

	ShowWindow(myWindow, iCmdShow);
	HDC myDeviceContext = GetDC(myWindow);

	PIXELFORMATDESCRIPTOR myPfd = { 0 };


	myPfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	myPfd.nVersion = 1;								

	myPfd.dwFlags = PFD_SUPPORT_OPENGL |				
		PFD_DOUBLEBUFFER |		
		PFD_DRAW_TO_WINDOW;		

	myPfd.iPixelType = PFD_TYPE_RGBA;					
	myPfd.cColorBits = 24;							
	myPfd.cDepthBits = 32;


	int chosenPixelFormat = ChoosePixelFormat(myDeviceContext, &myPfd);

	if (chosenPixelFormat == 0)
	{
		FatalAppExit(NULL, TEXT("ChoosePixelFormat() failed!"));
	}

	int result = SetPixelFormat(myDeviceContext, chosenPixelFormat, &myPfd);

	if (result == NULL)
	{
		FatalAppExit(NULL, TEXT("SetPixelFormat() failed!"));
	}

	HGLRC myRenderContext = wglCreateContext(myDeviceContext);

	wglMakeCurrent(myDeviceContext, myRenderContext);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	gluPerspective(45.0, (float)windowWidth / (float)windowHeight, 1, 1000);
	glViewport(0, 0, windowWidth, windowHeight);
	glClearColor(0.5, 0, 0, 1.0);				
#pragma endregion


	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				//quit
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear screen
		SwapBuffers(myDeviceContext);							// update graphics

	}

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(myRenderContext);
	ReleaseDC(myWindow, myDeviceContext);
	return msg.wParam;
}

#pragma region keep_this_bit_collapsed_too!

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{

	switch (message)
	{	
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}

	return DefWindowProc(hwnd, message, wparam, lparam);

}

#pragma endregion
