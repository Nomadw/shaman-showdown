 #pragma once

#include <windows.h>	// need to be able to create windows etc
#include <gl/gl.h>		// opengl header file
#include <gl/glu.h>		// glu header file - glu helps us set up the perspective projection
#include "Globals.h"

#include "Controls.h"

#include "Map.h"

#include <time.h>

// some basic numbers to hold the position and size of the window
#define WIDTH		800
#define HEIGHT		600
#define TOPLEFTX	50
#define TOPLEFTY	50

// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")

Renderer* renderer;


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow);

void draw(HDC deviceContext, Renderer * renderer);

float runTime = 0;
Map map = Map();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	MSG msg;								// this will be used to store messages from the operating system
	bool needToQuit = false;				// whether or not the player has quit the app

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
																		// Register that class with the Windows OS..
	RegisterClass(&myWindowClass);

	RECT rect;
	SetRect(&rect, TOPLEFTX,				// the top-left corner x-coordinate
		TOPLEFTY,				// the top-left corner y-coordinate
		TOPLEFTX + WIDTH,		// far right
		TOPLEFTY + HEIGHT);	// far left

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	HWND myWindow = CreateWindow(TEXT("my window class name"),		// window class to use - in this case the one we created a minute ago
		TEXT("OpenGL, No GLUT"),					// window title
		WS_OVERLAPPEDWINDOW,						// ??
		TOPLEFTX, TOPLEFTY,						// x, y
		TOPLEFTX + WIDTH, TOPLEFTY + HEIGHT,		// width and height
		NULL, NULL,								// ??
		hInstance, NULL);							// ??

	if (myWindow == NULL)
	{
		FatalAppExit(NULL, TEXT("CreateWindow() failed!"));
	}

	ShowWindow(myWindow, iCmdShow);

	HDC myDeviceContext = GetDC(myWindow);
	PIXELFORMATDESCRIPTOR myPfd = { 0 };

	myPfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);		// size of the pfd in memory
	myPfd.nVersion = 1;									// always 1

	myPfd.dwFlags = PFD_SUPPORT_OPENGL |				// OpenGL support - not DirectDraw
		PFD_DOUBLEBUFFER |				// double buffering support
		PFD_DRAW_TO_WINDOW;					// draw to the app window, not to a bitmap image

	myPfd.iPixelType = PFD_TYPE_RGBA;					// red, green, blue, alpha for each pixel
	myPfd.cColorBits = 24;								// 24 bit == 8 bits for red, 8 for green, 8 for blue.

	myPfd.cDepthBits = 32;								// 32 bits to measure pixel depth.

	int chosenPixelFormat = ChoosePixelFormat(myDeviceContext, &myPfd);
	int result = SetPixelFormat(myDeviceContext, chosenPixelFormat, &myPfd);

	HGLRC myRenderContext = wglCreateContext(myDeviceContext);

	wglMakeCurrent(myDeviceContext, myRenderContext);

	glMatrixMode(GL_PROJECTION);	// select the projection matrix, i.e. the one that controls the "camera"
	glLoadIdentity();				// reset it
	glOrtho(0, 10, 10, 0, -100, 100);
	glViewport(0, 0, WIDTH, HEIGHT);							// make the viewport cover the whole window
	glClearColor(0.5, 0, 0, 0);								// set the colour used for clearing the 
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Controls controls;
	renderer = new Renderer();

	renderer->loadTexture("test.tga", "missile1");
	int id = renderer->getTexture("missile1");
	float deltaTime = 0;

	map.loadMap("PLACEHOLDER");

	while (!needToQuit)
	{
		clock_t startFrameTime = clock();
		controls.clearKeysReleased();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				needToQuit = true;	// we want to quit asap
			}
			else
			{
				if (msg.message == WM_KEYDOWN)
				{
					controls.handleKeyPressed(msg.wParam);
				}
				if (msg.message == WM_KEYUP)
				{
					controls.handleKeyRelease(msg.wParam);
				}
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if (controls.isKeyPressed(VK_ESCAPE)) 
		{
			runTime += deltaTime;
		}
		draw(myDeviceContext, renderer);
		clock_t endFrameTime = clock();
		deltaTime= (float)(endFrameTime - startFrameTime) / (float)CLOCKS_PER_SEC;

	}
	wglMakeCurrent(NULL, NULL);

	// delete the rendering context, we no longer need it.
	wglDeleteContext(myRenderContext);

	// release our window's DC from the window
	ReleaseDC(myWindow, myDeviceContext);

	// end the program
	return msg.wParam;
}

void draw(HDC deviceContext, Renderer * renderer)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear the screen and the depth buffer

	//renderer->draw(0, runTime / 10.0f, 0, 1.0f);

	map.draw(renderer);

	SwapBuffers(deviceContext);									// put our triangles on the screen!

}

// this function is called when any events happen to our window
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{

	switch (message)
	{	
		// if they exited the window...	
	case WM_DESTROY:
		// post a message "quit" message to the main windows loop
		PostQuitMessage(0);
		return 0;
		break;
	}

	// must do this as a default case (i.e. if no other event was handled)...
	return DefWindowProc(hwnd, message, wparam, lparam);
}


