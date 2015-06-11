#include "TP1App.h"


TP1App::TP1App()
{

}

TP1App::TP1App(HINSTANCE hInstance, std::string WinCaption)
	:D3DApp(hInstance, WinCaption,
	D3DDEVTYPE_HAL, 
	D3DCREATE_HARDWARE_VERTEXPROCESSING)
{
	
}

TP1App::~TP1App()
{

}
