#include "D3DUtils.h"
#include "D3DApp.h"
#include "TP1App.h"
#include "Canon.h"

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPTSTR cmd, int showCmd)
{
	TP1App *app = new TP1App(hInstance, "TP1 - Peggle");
	
	gD3DApp = app;

	int assert = gD3DApp->Run();

	delete app;

	return assert;
}